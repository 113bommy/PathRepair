import fractions
from functools import reduce

def gcd(l):
    return reduce(fractions.gcd, l)
    
n, k = map(int, input().split())
a = list(map(int, input().split()))

x = gcd(a)
if k%x == 0 and k <= max(a):
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")