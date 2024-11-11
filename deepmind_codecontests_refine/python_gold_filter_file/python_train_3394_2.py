n,a=map(int,input().split())
c=[int(d) for d in input().split()]
res={}
res[a]=0
for i in c:
    if i not in res:
        res[i]=0
    if i!=a and res[i]!=-1:
        res[i]+=1
        if res[i]<=res[a]:
            res[i]=-1
    elif i==a:
        res[a]+=1
for i in res:
    if res[i]<res[a] and res[i]!=-1:
        res[i]=-1
f=True
for i in res:
    if res[i]!=-1 and i != a:
        print(i)
        f=False
        break
if f:
    print(-1)