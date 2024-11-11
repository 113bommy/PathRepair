n,k=map(int,input().split())
if(n>=k):
    for i in range((n//2),0,-1):
        if(n%i==0):
            if(i<k):
                x=i
                break
    z=n//x
    ans=z*k+x
    print(ans)
else:
    print(n+k)