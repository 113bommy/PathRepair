from fractions import gcd
from functools import reduce

n, m = map(int, input().split())
a = [int(i) for i in input().split()]
c = 1
while a[0] % 2 == 0:
    a[0] //= 2
    c *= 2
a[0] *= c
for ai in a[1:]:
    if ai % c or (ai // c) % 2 == 0:
        print(0)
        break
else:
    lcm = reduce(lambda x, y: x * y // gcd(x, y), a) // 2
    print(m // lcm - m // (2 * lcm))