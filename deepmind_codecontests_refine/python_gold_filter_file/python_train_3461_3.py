import os
import sys
if os.path.exists('/mnt/c/Users/Square/square/codeforces'):
    f = iter(open('E.txt').readlines())
    def input():
        return next(f)
    # input = lambda: sys.stdin.readline().strip()  
else:
    input = lambda: sys.stdin.readline().strip()

fprint = lambda *args: print(*args, flush=True)

p = 998244353 
n, k = map(int, input().split())
res = 0

def ncr(n, r, p):
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i+1)) % p
    return (num * pow(den, p-2, p))

res = 0
if k == 1:
    print(n)
else:
    k -= 1
    for i in range(1, n+1):
        if n // i > k:
            res += ncr(n // i - 1, k, p)
    print(res % p)