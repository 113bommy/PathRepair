n,k=map(int,input().split())
ans,res=-10000000000000,0
#print(ans)
for i in range(n):
    f,t = map(int, input().split())
    if t<=k:
        temp=f
        ans=max(temp,ans)
    else:
        temp=f-t+k
        ans=max(temp,ans)
print(ans)