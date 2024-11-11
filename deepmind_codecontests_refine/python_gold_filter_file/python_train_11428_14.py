n,x,m=map(int, input().split())
a=x
ans=a
flg=[0]*m
flg[a]=1
l=[a]
lp=-1

for i in range(1,m+1):   
    if n <= i:
        break
    tmp=(a*a)%m
    a=tmp
    if flg[a]==1:
        lp = l.index(a)
        break
    else:    
        ans+=tmp
        l.append(a)
        flg[a]=1

if lp != -1:
    l2 = l[lp:]
    tmp = sum(l2)
    b=(n-len(l))//len(l2)
    c=n-len(l)-b*len(l2)
    ans=ans+(b*tmp)+sum(l2[:c])

print(ans)