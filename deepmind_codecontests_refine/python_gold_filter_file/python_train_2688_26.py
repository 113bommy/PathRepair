# from math import gcd
from fractions import gcd
import sys

N, M = map(int, input().split())
S = input()
T = input()

d = gcd(N, M)
m = N * M // d

for i in range(d):
    if S[i * (N // d)] != T[i * (M // d)]:
        print(-1)
        sys.exit()

print(m)
