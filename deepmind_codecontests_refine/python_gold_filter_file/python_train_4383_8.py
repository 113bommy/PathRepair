n=int(input())
a=list(map(int,input().split()))
a.sort()
ct=[]
nm=[]
f=a[0]
c=0
for i in range(n):
    if a[i]==f:
        c+=1
    else:
        nm.append(f)
        f=a[i]
        ct.append(c)
        c=1
nm.append(f)
ct.append(c)
ex=ct[0]
ans=0
for i in range(1,len(nm)):
    if ct[i]<=ex:
        ans+=ct[i]
    else:
        ans+=ex
        ex=ct[i]
print(ans)