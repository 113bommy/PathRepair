import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


M = 10**9+7
n = int(input())
p = list(map(int, input().split()))
g1 = [None]*(n+10)
v = 1
g1[0] = 1
for i in range(1,len(g1)):
    v *= i
    v %= M
    g1[i] = v
    
def init(bit, values):
    for i,v in enumerate(values):
        add(bit,i+1,v)
#a1 ~ aiまでの和 O(logn)
def query(bit,i):
    res = 0
    while i > 0:
        res += bit[i]
        i -= i&(-i)
    return res

#ai += x(logN)
def add(bit,i,x):
    if i==0:
        raise RuntimeError
    while i <= len(bit)-1:
        bit[i] += x
        i += i&(-i)
    return


index = [i for i,num in enumerate(p) if num==0]
used = [False]*n
for i in range(n):
    if p[i]>0:
        used[p[i]-1] = True
nl = []
for i in range(n):
    if not used[i]:
        nl.append(i+1)
nl.sort()
scores = [0]*(n+1) # scores[i]: nlのうちiより大きいものの個数
v = len(nl)
cur = 0
for i in range(1,n+1):
    if nl and cur<len(nl) and nl[cur]<i:
#     if nl and nl[cur]<i:
        cur += 1
        v -= 1
    scores[i] = v
ans = 0
bit = [0]*(n+1)
s = set(index)
val = 0
pp = len(index) # 欠損の個数
ss = sum(nl)
num = 0
inv2 = pow(2, M-2, M)
for i in range(n):
    if i in s:
        ans += (g1[pp-1] * (ss - pp - val - pp*(num)*inv2)) * g1[n-i-1]
        num += 1
    else:
        ans += (g1[pp] * (p[i]-query(bit, p[i])-1) - g1[pp-1]*num*(len(nl)-scores[p[i]])) * g1[n-i-1]
        add(bit, p[i], 1)
        val += scores[p[i]]
    ans %= M
#     print(ans, val)
print((ans + g1[pp])%M)