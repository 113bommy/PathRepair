from math import gcd
from functools import reduce
n, m = [int(i) for i in input().split()]
x = [int(i) for i in input().split()]
p = [int(i) for i in input().split()]
s = [x[i+1] - x[i] for i in range(n-1)]
g = reduce(gcd, s)
for i in range(m):
    if g%p[i] == 0:
        print('YES')
        print(x[0], i+1)
        break
else:
    print('NO')
