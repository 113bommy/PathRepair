n=int(input())
A=list(map(int,input().split()))

ans=set()
for i in range(n-1,-1,-1):
  for j in range(i+1,n+1,i+1):
    if j in ans:
      A[i]+=1
  if A[i]%2:
    ans.add(i+1)
print(len(ans))
print(*ans)
