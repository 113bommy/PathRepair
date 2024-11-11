n,k=map(int,input().split())
ans=0
while(n>0):
    n=n//k
    ans+=1
print(ans)