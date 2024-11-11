N,M=[int(x) for x in input().split()]
G=[-1] * N
W=[0] * N
E=[]

result=[]
ans = int(N * (N-1) / 2)

def union(i,j):
    gi=find(i)
    gj=find(j)

    if(gi!=gj):
        if W[gi] > W[gj]:
            G[gi]+=G[gj]
            G[gj]=gi
        else:
            G[gj]+=G[gi]
            G[gi]=gj
            if W[gi]==W[gj]:
                W[gj]+=1

def find(i):
    if G[i]<0:
        return i;
    else:
        G[i]=find(G[i])
        return G[i]

for m in range(M):
    A,B=[int(x) for x in input().split()]
    E.append((A-1,B-1))

for m in range(M):
    result.append(ans)
    if(ans>0):
        A,B=E.pop()
        ga,gb=find(A),find(B)
        if (ga!=gb):
            ans=ans-(G[ga]*G[gb])
            union(A,B)

for r in reversed(result):
    print(r)
