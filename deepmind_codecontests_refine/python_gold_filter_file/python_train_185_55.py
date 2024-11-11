N, P = [int(_) for _ in input().split()]

from math import sqrt, ceil
from collections import defaultdict

rootp = ceil(sqrt(P))

cs = defaultdict(int)

x = P
for i in range(2, rootp):
    while x % i == 0:
        cs[i] += 1
        x //= i
cs[x] += 1

#print(cs)

result = 1

for n in cs:
    x = cs[n] // N
    if x:
        result *= n ** x

print(result)
