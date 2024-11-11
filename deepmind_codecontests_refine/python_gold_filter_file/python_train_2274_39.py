from fractions import gcd

N, K = map(int, input().split())
A = list(map(int, input().split()))

g = A[0]
for a in A[1:]:
    g = gcd(a, g)

if max(A) >= K and K % g == 0:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
