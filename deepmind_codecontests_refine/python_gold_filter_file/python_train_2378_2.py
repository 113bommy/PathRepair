import sys
sys.setrecursionlimit(10**6)
n,m=map(int,input().split())
s=[[]for i in range(n+1)]
c=[0]*(n+1)
for i in range(m):
    a,b=map(int,input().split())
    s[a].append(b)
    s[b].append(a)
def dfs(v,t):
    c[v]=t
    for i in s[v]:
        if c[i]==t:
            return False
        if c[i]==0 and not dfs(i,-t):
            return False
    else:
        return True
if dfs(1,1):
    q=c.count(1)
    print((n-q)*q-m)
else:
    print((n*(n-1)//2)-m)
