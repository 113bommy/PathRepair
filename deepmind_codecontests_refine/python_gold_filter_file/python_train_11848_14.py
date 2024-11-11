N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
ans = 0
for i in range(N):
  ans += min(A[i]+A[i+1],B[i])
  A[i+1] -= max(0,min(A[i+1],B[i]-A[i]))
print(ans)