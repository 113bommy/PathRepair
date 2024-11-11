def sum(BIT, i):
    s = 0
    while i > 0:
        s += BIT[i]
        i -= i & (-i)
    return s


def update(BIT, i, v):
    while i < len(BIT):
        BIT[i] += v

        i += i & (-i)


def find(fen, k):
    curr = 0
    ans = 0
    prevsum = 0
    for i in range(19, -1, -1):
        if ((curr + (1 << i) < n) and fen[curr + (1 << i)] + prevsum < k):
            ans = curr + (1 << i)
            curr = ans
            prevsum += fen[curr]
    return ans + 1

def Rank(x,BIT) :

    return sum(BIT,x)




n = int(input())
p = list(map(int, input().split()))
q = list(map(int, input().split()))

factp = []
factq = []




BIT = [0] * (n + 1)
for j in range(n):
    update(BIT,j+1,1)


for val in p:
    factp.append(Rank(val+1,BIT)-1)
    update(BIT,val+1,-1)




BIT = [0] * (n + 1)
for j in range(n):
    update(BIT,j+1,1)


for val in q:
    factq.append(Rank(val+1,BIT)-1)
    update(BIT,val+1,-1)





carry = 0
for i in range(n - 1, -1, -1):
    radix = n - i
    factp[i] = factp[i] + factq[i] + carry
    if factp[i] < radix:
        carry = 0
    else:
        carry = 1
        factp[i] -= radix


BIT = [0] * (n + 1)
for j in range(n):
    update(BIT,j+1,1)
res=[]
for i in range(n):
    k = factp[i]+1
    res.append(find(BIT,k)-1)
    update(BIT,res[-1]+1,-1)

print(*res)