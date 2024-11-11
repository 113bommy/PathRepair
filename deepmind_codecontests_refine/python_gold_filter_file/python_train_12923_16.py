n,b = list(map(int,input().split()))
primes = []

def seive():
    nn = 1000100
    vis = [False] * nn
    for i in range(4,nn,2):
        vis[i] = True
    i = 3
    vis[0],vis[1] = True, True
    while(i*i<nn):
        if(not vis[i]):
            j = i*i
            while(j<nn):
                vis[j] = True
                j += 2*i
        i+=2
    for i in range(nn):
        if(not vis[i]):
            primes.append(i)
    #print(len(primes))
seive()

def find_factors(nn):
    ans = []
    for i in primes:
        if(nn%i==0):
            count = 0
            while(nn%i==0):
                count+=1
                nn/=i
            ans.append((i,count))
    if nn > 1:
        ans.append((nn,1))
    return ans

f = find_factors(b)

def find_ans(t):
    ff,no = t
    ans = 0
    temp = ff
    while(n//ff):
        ans += n//ff
        ff *= temp
    return ans//no

final_ans = find_ans(f[0])

for i in range(1,len(f)):
    final_ans = min(final_ans, find_ans(f[i]))
print(int(final_ans))