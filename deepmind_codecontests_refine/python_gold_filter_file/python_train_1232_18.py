from collections import deque
n=int(input())
g=[[] for i in range(n)]
for i in range(n-1):
    a,b,c=map(int,input().split())
    g[a-1].append([b-1,c])
    g[b-1].append([a-1,c])
q,k=map(int,input().split())
qu=deque([[k-1,0]])
v=[0]*n
d=[0]*n
while len(qu)>0:
    s=qu.popleft()
    v[s[0]]=1
    for j in g[s[0]]:
        if not v[j[0]]:
            v[j[0]]=1
            d[j[0]]=s[1]+j[1]
            qu+=[[j[0],d[j[0]]]]
for i in range(q):
    x,y=map(int,input().split())
    print(d[x-1]+d[y-1])
