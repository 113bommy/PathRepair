n,k=map(int,input().split())
a=list(map(int,input().split()))
s=a
s=sorted(a)
m=0
for i in range(0,n):
    d=sum(s[0:i])
    e=sum(s[0:i+1])
    if d<=k and e>k:
        m=i
        break
if k>=sum(s):
    m=n
print(m)
for i in range(0,m):
    print((a.index(s[i])+1),end=' ')
    a[a.index(s[i])]=-1
    