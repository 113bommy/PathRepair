import fractions
import functools

def lcm(n1, n2):
    return n1 * n2 // fractions.gcd(n1, n2)

N, M = map(int, input().split())
A = list(map(int, input().split()))
for i in range(N):
    A[i] //= 2

lcmA = functools.reduce(lcm, A)
gcdA = functools.reduce(fractions.gcd, A)
if (lcmA // gcdA) % 2 == 0:
    print(0)
else:
    print((M // lcmA + 1) // 2)

