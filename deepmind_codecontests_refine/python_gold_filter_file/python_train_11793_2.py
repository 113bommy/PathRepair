n, R, r = map(int, input().split())
from math import asin, pi
if r > R: print('NO')
elif R>=r>R/2: print('YES' if n == 1 else 'NO')
else: print('YES' if pi/asin(r/(R-r)) >= n-10**-6 else 'NO');
