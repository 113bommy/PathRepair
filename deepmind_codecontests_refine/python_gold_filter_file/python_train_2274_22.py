from fractions import gcd
N, K = map(int, input().split())
A = list(map(int, input().split()))

t = A[0]
for a in A:
    t = gcd(a, t)

if K % t == 0 and K < max(A) or K in A:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
