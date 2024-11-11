N = int(input())
A = list(map(int, input().split()))
isOK = True
B = [0]*(N+1)
B[0] = 1-A[0]
M = 1
i = 1
while i <= N:
  B[i] = B[i-1]*2-A[i]
  i += 1
if B[-1] < 0 or N > 0 and A[-1] == 0:
  isOK = False
B[-1] = A[-1]
i = N-1
while i >= 0:
  if B[i] < 1 or i > 0 and B[i] > B[i-1]*2:
    isOK = False
    break
  else:
    B[i] = min(B[i], B[i+1])+A[i]
  i -= 1
print(-1 if not isOK else sum(B))
