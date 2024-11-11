from collections import defaultdict as dd
from collections import deque
import bisect
import heapq

def ri():
    return int(input())

def rl():
    return list(map(int, input().split()))


def solve():
    n, m = rl()
    A = []
    out = []
    for i in range(n):
        A.append(rl())
        out.append([3] + [4] * (m - 2) + [3])

    out[0][0] = 2
    out[0][-1] = 2
    out[-1][0] = 2
    out[-1][-1] = 2

    for i in range(1, m - 1):
        out[0][i] = 3
        out[-1][i] = 3

    for j in range(1, n - 1):
        out[j][0] = 3
        out[j][-1] = 3

    for i in range(n):
        for j in range(m):
            if A[i][j] > out[i][j]:
                print ("NO")
                return

    print ("YES")
    for i in range(n):
        print (' '.join(map(str, out[i])))





mode = 'T'

if mode == 'T':
    t = ri()
    for i in range(t):
        solve()
else:
    solve()
