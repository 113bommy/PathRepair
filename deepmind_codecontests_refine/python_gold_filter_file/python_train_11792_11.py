import sys
input = sys.stdin.readline
import math

############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input().strip()
    return(list(s[:len(s)]))
def invr():
    return(map(int,input().strip().split()))



def from_file(f):
    return f.readline



def solve(n ,k, l1, r1, l2, r2):
    C = min(r1, r2) - max(l1, l2)

    if C >=0:
        # intersecting case
        D = abs(l2-l1) + abs(r2-r1)
        delta = k - n * C
        if delta <= 0:
            return 0
        res = min(delta, n * D)
        delta -= res
        if delta != 0:
            res += 2 * delta
        return res

    else:
        C = -C
        M = float('inf')
        for i in range(1, n+1):
            res = C * i

            D = max(r1, r2) - min(l1, l2)
            delta = k
            if delta == 0:
                res = 0
            else:
                res += min(delta, i * D)
                delta -= min(delta, i * D)
                if delta != 0:
                    res += 2 * delta
            M = min(res, M)
        return M





# with open('4.txt') as f:
#     input = from_file(f)
t = inp()
for _ in range(t):
    n, k = invr()
    l1, r1 = invr()
    l2, r2 = invr()
    print(solve(n, k, l1, r1, l2, r2))