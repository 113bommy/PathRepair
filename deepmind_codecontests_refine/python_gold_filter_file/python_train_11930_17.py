n,t,k,d=[int(x) for x in input().split(' ')]
t1=0
t2=0
if n%k==0:
    t1=(n//k)*t
else:
    t1=(n//k+1)*t
c=0
while c<n:
    t2+=1
    if t2%t==0:
        c+=k
    if (t2-d)>0 and (t2-d)%t==0:
        c+=k
if t2<t1:
    print('YES')
else:
    print('NO')