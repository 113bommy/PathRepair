n=int(input())
k=int(input())
ans=1
for i in range(n):
  ans=min(k+ans,2*ans)
print(ans)