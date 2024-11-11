n,m=map(int,input().split())
G={}
v=0
c=-1
for i in range(m):
    a,b=map(int,input().split())
    try:
        G[a].append(b)
        if (len(G[a])>v):
            c=a
            v=len(G[a])
    except:
        G[a]=[b]
        if (v<1):
            c=a
            v=1

    try:
        G[b].append(a)
        if (len(G[b])>v):
            c=b
            v=len(G[b])
    except:
        G[b]=[a]
        if (v<1):
            c=b
            v=1

A={}
for i in G.keys():
    A[i]=-1

q=[c]
A[c]=1
while(len(q)!=0):
    a=q.pop()
    for i in G[a]:
        if (A[i]==-1):
            print(a,i)
            q.append(i)
            A[i]=1
