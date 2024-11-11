N = int(input())
A = [int(i) for i in input().split()]
A.sort()
S = -A[-1]

for i in range(N):
  S += A[N-i//2-1]
print(S)