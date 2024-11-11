n,x=map(int,input().split())
a=list(map(int,input().split()))
M=1
I=1
ans=0
for i in range(len(a)):
    if a[i]<=n:
        m=n-n%a[i]
        if M<=m:
            M=m
            ans=m//a[i]
            I=i+1
if n>0:
    print(I,ans)
else:
    print(I,0)
