import fractions
from functools import reduce

n=int(input())
a=list(map(int,input().split()))

print(reduce(fractions.gcd,a))