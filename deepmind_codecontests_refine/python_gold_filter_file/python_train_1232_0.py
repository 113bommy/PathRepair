import sys
sys.setrecursionlimit(1000000)
n=int(input())
g=[[] for _ in range(n)]
for _ in range(n-1):
    a,b,c=map(int,input().split())
    g[a-1].append((b-1,c))
    g[b-1].append((a-1,c))
q,k=map(int,input().split())
d=[-1]*n
def f(k,c):
    d[k]=c
    for i,v in g[k]:
        if d[i]==-1:
            f(i,c+v)
f(k-1,0)
for _ in range(q):
    x,y=map(int,input().split())
    print(d[x-1]+d[y-1])