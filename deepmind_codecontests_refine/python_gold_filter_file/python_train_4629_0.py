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

def debug(*var, sep = ' ', end = '\n'):
    print(*var, file=sys.stderr, end = end, sep = sep)

INF = 10**20
MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))
from math import gcd
from math import ceil
from collections import defaultdict as dd, Counter
from bisect import bisect_left as bl, bisect_right as br

n, = I()
if n <= 3:
    print('NO')
    exit()
print('YES')
if n % 2:
    print('1 + 2 = 3')
    print('5 - 3 = 2')
    print('2 * 3 = 6')
    print('6 * 4 = 24')
    for i in range(7, n + 1, 2):
        print(i, '-', i - 1, '=', 1)
        print(24, '*', 1, '=', 24)
else:
    print('1 * 2 = 2')
    print('3 * 4 = 12')
    print('2 * 12 = 24')
    for i in range(6, n + 1, 2):
        print(i, '-', i - 1, '=', 1)
        print(24, '*', 1, '=', 24)