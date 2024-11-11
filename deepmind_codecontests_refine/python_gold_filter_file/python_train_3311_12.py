r,g,b,n=map(int,input().split())
ans=0
for i in range(n+1):
    for j in range(n+1):
        if (n-i*r-j*g)%b==0 and n-i*r-j*g>=0:
            ans+=1
print(ans)