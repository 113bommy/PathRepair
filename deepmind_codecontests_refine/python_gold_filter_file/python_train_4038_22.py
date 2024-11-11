n,m,x=map(int,input().split())
a=[]
ans=-1
t=[0]*(m+1)
for i in range(n):
    a.append(list(map(int,input().split())))
for i in range(2 ** n):
    for j in range(n):
        if (i >> j) & 1:
            for lnd,l in enumerate(a[j]):
                t[lnd]+=l
    if ans==-1 or ans > t[0]:
        if min(t[1:m+1]) >= x:
            ans = t[0]
    t=[0]*(m+1)
print(ans)