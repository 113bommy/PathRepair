n=int(input())
if(n%4>1):
    print(-1)
else:
    ans=[0]*(n+1)
    i,j,a,b=1,n,1,n
    while(i<j and a<=n and b>=1):
        ans[i],ans[j]=a+1,b-1
        ans[i+1],ans[j-1]=b,a
        i+=2
        j-=2
        a+=2
        b-=2
    if(i==j):
        ans[i]=a
    for i in range(1,n+1):
        print(ans[i],end=' ')
        