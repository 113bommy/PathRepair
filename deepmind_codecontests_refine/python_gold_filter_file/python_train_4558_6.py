n=int(input())
ans=n*(n+1)*(n+2)//6
for i in range(n-1):
    u=list(map(int,input().split()))
    ans-=min(u)*(n-max(u)+1)
print(ans)