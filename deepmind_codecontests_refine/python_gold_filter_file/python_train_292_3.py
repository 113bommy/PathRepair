N = int(input())
A = list(map(int, input().split()))
ans = 0
for i in range(len(A)-1):
  if (i+1 == A[i]):
    ans += 1
    A[i],A[i+1] = A[i+1],A[i]
if (A[-1] == len(A)):
  ans += 1
print(ans)