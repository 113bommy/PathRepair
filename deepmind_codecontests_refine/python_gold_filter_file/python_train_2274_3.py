n, k = map(int, input().split())
A = list(map(int, input().split()))
import fractions
a = A[0]
for i in range(1, n):
  a = fractions.gcd(a, A[i])
if max(A) < k:
  print('IMPOSSIBLE')
elif k%a == 0:
  print('POSSIBLE')
else:
  print('IMPOSSIBLE')