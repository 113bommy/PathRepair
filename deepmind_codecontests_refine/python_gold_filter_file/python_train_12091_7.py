n,m,k=map(int,input().split())
li=list(map(int,input().split()))
li.sort()
sumd=0
ans=0
l=m//(k+1)
c=m%(k+1)
ans=k*li[n-1]+li[n-2]
if m>=k:
    ans=l*ans+c*li[n-1]
else:
    ans=ans*max(li)
print(ans)