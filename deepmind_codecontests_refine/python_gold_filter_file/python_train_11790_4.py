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

INF = 10**20
MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))
from math import gcd
from math import ceil
from collections import defaultdict as dd, Counter
from bisect import bisect_left as bl, bisect_right as br

t, = I()
while t:
    t -= 1
    n, = I()
    a = [0] * n
    g = []
    assigned = [0] * n
    unassigned = []
    ans = "OPTIMAL"
    for i in range(n):
        l = I()
        for j in l[1:]:
            if not assigned[j - 1]:
                assigned[j - 1] = 1
                break
        else:
            unassigned.append(i)
    for i in range(n):
        if not assigned[i]:
            print("IMPROVE")
            print(unassigned[0] + 1, i + 1)
            break
    else:
        print(ans)
