n,k = map(int,input().split())
A = list(map(int,input().split()))

for j in range(min(k,45)):
  B = [0]*(n)
  for i in range(n):
    l = max(0,i-A[i])
    r = min(n-1,i+A[i])
    B[l] += 1
    if r+1 < n:
      B[r+1] -= 1  
      
  for i in range(1,n):
    B[i]+=B[i-1]
  
  A = B.copy()
print(*B)  