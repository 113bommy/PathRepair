import sys
import math

Q = input() # cin >> - scanf..

#[0,1,...,q)

for q in range(0,int(Q)):
    a,b,n,s = input().strip().split()
    a = int(a)
    b = int(b)
    n = int(n)
    s = int(s)
    if math.floor(s / n) <= a and s % n <= b:
        print('YES')
    elif math.floor(s / n) <= a and s % n > b:
        print('NO')
    elif math.floor(s / n) > a and s - n*a -b <= 0:
        print('YES')
    else:
        print('NO')
    
