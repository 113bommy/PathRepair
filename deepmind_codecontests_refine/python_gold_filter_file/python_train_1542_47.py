n=int(input())
v=list(map(int,input().strip().split()))
a=[0]*n
for i in range(n-1,-1,-1):
  c=0
  for j in range(i,n,i+1):
    c ^= a[j]
  if c != v[i]:
    a[i] = 1
ans = []
for i in range(n):
  if a[i]: ans.append(i+1)
print(len(ans))
print(*ans)