n,k=map(int,input().split())
f=0
c=0
for i in range(35):
    d=n
    c=0
    d=n-i*k
    t=d 
    while(d>0):
        c+=d%2
        d//=2
    if c<=i and i<=t:
        f=1
        print(i)
        break
if f==0:
    print(-1)