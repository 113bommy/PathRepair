
n = int(input())
ind=[0]*(n+1)
cnt=0
for i in range(n-1):
    u,v=map(int, input().split())
    ind[u]+=1
    ind[v]+=1
ok=sum(ind[i]>2 for i in range(1,n+1)) <2
if not ok:
    print("No")
    exit()
print("Yes")
centre=ind.index(max(ind))
leaf=[]
for i in range(1,n+1):
    if ind[i]==1:
        leaf.append(i)
if max(ind)==2 or n==2:
    print(1)
    print(leaf[0] ,leaf[1])
else:
    print(len(leaf))
    for i in leaf:
        print(*[centre ,i])