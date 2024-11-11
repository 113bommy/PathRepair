N, Q = map(int, input().split())
A = [int(x) for x in input().split()]
B = [a for a in A]
for i in range(N - 2, -1, -1):
  B[i] += B[i + 1]
C = [a for a in A]
for i in range(2, N):
  C[i] += C[i - 2]
D = [0 for i in range(N)]
for i in range(1, N + 1):
  if N - 1 - 2 * i < 0:
    break
  D[N - i] = (A[N - 1 - i] + A[N - 1 - 2 * i]) // 2 + 1
E = [b for b in B]
for i in range(1, N + 1):
  if N - 2 * i - 1 < 0:
    break
  E[N - i] += C[N - 2 * i - 1]
def binsearch(upper, lower, x):
  if x >= D[upper]:
    return upper
  if upper - lower == 1:
    return lower
  else:
    mid = (upper + lower) // 2
    if D[mid] <= x:
      return binsearch(upper, mid, x)
    else:
      return binsearch(mid, lower, x)
for q in range(Q):
  x = int(input())
  print(E[binsearch(N - 1, 0, x)])