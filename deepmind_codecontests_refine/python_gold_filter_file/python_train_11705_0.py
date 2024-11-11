#!/usr/bin/python3 -SOO
from math import sqrt
a,b = map(int,input().strip().split())
for i in range(1,a):
    x = a*a - i*i
    if x<=0 or int(sqrt(x) + 0.5)**2 != x: continue
    u = b*i/a
    v = b*sqrt(x)/a
    if abs(u-int(u)) < 0.0005 and abs(v-int(v)) < 0.0005 and int(v)!=i:
        print('YES')
        print('0 0')
        print('%d %d'%(-int(u),int(v)))
        print('%d %d'%(int(sqrt(x)),i))
        break
else:
    print('NO')
