from sys import stdin, stdout
from math import sqrt

n, k = map(int, stdin.readline().split())
k = min(k, n)

def sqrtt(x):
    l = 1
    r = x
    
    while (r - l > 10 ** (-3)):
        m = (r + l) / 2
        
        if m * m >= x:
            r = m
        else:
            l = m

    if int(r) * int(r) >= x:
        return int(r)
    else:
        return r


D = 9 + 8 * (n - k - 1)
day1 = (sqrtt(D) - 3) / 2

if day1 - int(day1) == 0:
    stdout.write(str(int(day1) + 1 + k))
else:
    stdout.write(str(int(day1) + 2 + k))