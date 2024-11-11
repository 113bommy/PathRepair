
import sys
from fractions import gcd
[print("{} {}".format(gcd(k[0], k[1]), (k[0] * k[1]) // gcd(k[0], k[1]))) for i in sys.stdin for k in [[int(j) for j in i.split()]]]