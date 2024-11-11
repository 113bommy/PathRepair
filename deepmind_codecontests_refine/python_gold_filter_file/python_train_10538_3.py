n, m, p = [int(x) for x in input().split()]
a=list()
b=list()
a=[int(x) for x in input().split()]
b=[int(x) for x in input().split()]
ok=True
ans=0
for i in range(n):
    if a[i]%p!=0 and ok==True:
        ok=False
        ans+=i
ok=True
for i in range(m):
    if b[i]%p!=0 and ok==True:
        ok=False
        ans+=i
print(ans)