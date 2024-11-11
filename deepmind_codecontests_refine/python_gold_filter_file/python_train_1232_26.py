import sys
sys.setrecursionlimit(1000000)

N=int(input())
n=[[]for i in range(N+1)]

for i in range(N-1):
    a,b,c=map(int,input().split())
    n[a].append([b,c])
    n[b].append([a,c])
    
L=[-1 for i in range(N+1)]

Q,K=map(int,input().split())

L[K]=0

def dfs(x):
    for i in n[x]:
        if L[i[0]]==-1:
            L[i[0]]=L[x]+i[1]
            dfs(i[0])
dfs(K)
#print(n)
#print(L)

for i in range(Q):
    x,y=map(int,input().split())
    print(L[x]+L[y])