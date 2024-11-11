import fractions
from functools import reduce

N = int(input())
As = map(int, input().split())

print(reduce(fractions.gcd, As))
