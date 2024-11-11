t=int(input())
for _ in range(t):
    n=int(input()) 
    if n==2 or n==3:
        print(-1)
    else:
        if n%2==0:
            ans=[]
            k=n-1
            while(k>=1):
                ans.append(k)
                k-=2
            ans.append(4)
            ans.append(2)
            k=6
            while(k<=n):
                ans.append(k)
                k+=2
        else:
            ans=[]
            k=n
            while(k>=1):
                ans.append(k)
                k-=2
            ans.append(4)
            ans.append(2)
            k=6
            while(k<=n-1):
                ans.append(k)
                k+=2
        print(*ans) 
            