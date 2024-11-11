#code
t=int(input())
while t:
    n=int(input())
    if(n<4):
        print(-1)
    else:    
        ans=[0 for i in range(n)]
        for i in range(n//4):
            ans[4*i]=4*i+2
            ans[4*i+1]=4*i+4
            ans[4*i+2]=4*i+1
            ans[4*i+3]=4*i+3
        if(n%4==1):
            ans[n-1]=n
        elif(n%4==2):
            ans[n-2]=ans[n-3]
            ans[n-3]=n-1
            ans[n-1]=n
        elif(n%4==3):
            ans[n-2]=ans[n-4]
            ans[n-4]=n-2
            ans[n-3]=n
            ans[n-1]=n-1
        print(*ans)
    t-=1    