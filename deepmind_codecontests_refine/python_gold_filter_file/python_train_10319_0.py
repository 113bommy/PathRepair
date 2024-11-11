n,k=map(int,input().split())
a=list(map(int,input().split()))
ans=0
while k>=min(a):
    s=0;count=0
    for i in a:
        if i<=k:
            k-=i
            s+=i
            count+=1
    ans+=(k//s)*count + count
    k-=(k//s)*s
    #print(k,ans)
print(ans)    
        