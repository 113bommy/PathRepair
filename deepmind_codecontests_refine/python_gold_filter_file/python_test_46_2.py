
for _ in range(int(input())):
    n=int(input())
    li=list(map(int,input().split()))
    ans=0 
    m=max(li)
    if(li[n-1]!=m):
        ans=ans+1 
    for i in range(n-2,0,-1):
        if(li[i]>li[i+1]):
            if(li[i]==m):
                break
            else:
                ans=ans+1
        else:
            li[i],li[i+1]=li[i+1],li[i]
    print(ans)
        
        