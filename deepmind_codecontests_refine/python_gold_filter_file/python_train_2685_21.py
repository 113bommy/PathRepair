from fractions import gcd
from functools import reduce

N, M, *A = map(int, open(0).read().split())

Y = reduce(lambda a, b: a * b // gcd(a, b), A)

if any((Y // a) % 2 == 0 for a in A):
    print(0)
    quit()

print(M // (Y // 2) - (M // Y))