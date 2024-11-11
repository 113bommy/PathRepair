import sys
def fastio():
    from io import StringIO
    from atexit import register
    global input
    sys.stdin = StringIO(sys.stdin.read())
    input = lambda : sys.stdin.readline().rstrip('\r\n')
    sys.stdout = StringIO()
    register(lambda : sys.__stdout__.write(sys.stdout.getvalue()))
fastio()

def debug(*var):
    print(*var, file=sys.stderr)

INF = 10**20
MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))
from math import gcd
from collections import defaultdict as dd, Counter
from bisect import bisect_left as bl, bisect_right as br

Q, = I()

while Q:
    Q -= 1
    n, p, k = I()
    a = I()
    a.sort()
    t = a[:]
    for i in range(k, n):
        t[i] += t[i-k]
    ans = 0
    for i in range(n):
        if t[i] <= p:
            ans = i + 1
    print(ans)