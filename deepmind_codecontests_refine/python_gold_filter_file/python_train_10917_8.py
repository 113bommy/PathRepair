from math import gcd
from sys import stdin

for line in stdin:
    a,b = [int(i) for i in line.split()]
    g = gcd(a,b)
    print(g,int(a*b/g))