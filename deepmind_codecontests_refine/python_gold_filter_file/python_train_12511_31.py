n,k=map(int,input().split())
t=0
for i in range(1,n+1):
    x=i*(i+1)//2
    if(x>=k):
        t=i
        break
for i in range(t,n+1):
    x=i*(i+1)//2
    y=x-k
    if(i+y==n):
        print(y)
        break
    

    
