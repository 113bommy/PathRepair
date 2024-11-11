t=int(input())
for i in range(t):
    a,b,n=map(int,input().split())
    ans=0
    final=0
    if a>b:
        ans=1
    else:
        ans=0
    while a<=n and b<=n:
        if ans%2==0:
            a+=b
            ans+=1
            final+=1
        else:
            b+=a
            ans+=1
            final+=1
    print(final)
            
            
        