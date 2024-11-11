import os,io
from sys import stdout
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
import collections

def binomial_coefficient(n, k):
    if 0 <= k <= n:
        ntok = 1
        ktok = 1
        for t in range(1, min(k, n - k) + 1):
            ntok *= n
            ktok *= t
            n -= 1
        return ntok // ktok
    else:
        return 0

map = {
    9: [7, 3, 3, 2],
    8: [7, 2, 2, 2],
    7: [7],
    6: [5, 3],
    5: [5],
    4: [3, 2, 2],
    3: [3],
    2: [2],
    1: [],
    0: []
}

def fact(n):
    if n == 1:
        return [1]
    return [n] + fact(n-1)

n = int(input())
a = int(input())

l = []
for i in range(n):
    d = a % 10
    a = a // 10
    l += map[d]

l = sorted(l, reverse=True)

r = "".join([str(e) for e in l])
print(r)
