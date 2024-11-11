n=int(input())
a=list(map(int,input().split()))
if a==[2,1]:
    print(1,2)
    exit()
L=0
if a[L]==1:
    while L<n-1:
        if a[L+1]-a[L]!=1:
            break
        L+=1
if L==n-1:
    print(0,0)
    exit()
L+=1    
R=a.index(L+1)
a=a[:L]+a[R:L-1:-1]+a[R+1:]
b=[x for x in range(1,n+1)]
if a==b:
    print(L+1,R+1)
else:
    print(0,0)
