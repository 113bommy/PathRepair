import sys
input = sys.stdin.readline
def getInt(): return int(input())
def getVars(): return map(int, input().split())
def getList(): return list(map(int, input().split()))
def getStr(): return input().strip()
## -------------------------------

t = getInt()
for _ in range(t):
    n, x = getVars()
    a = getList()
    s = 0
    res = 0
    d = {}
    for i in range(n):
        if a[i] >= x:
            res += 1
            s += a[i] - x
        else:
            razn = x - a[i]
            if razn not in d:
                d[razn] = 0
            d[razn] += 1
##    print(d, s, res)
    keys = list(d.keys())
    keys.sort()
    for k in keys:
##        print(s, k, d[k], s-k*d[k])
        if s - k*d[k] >= 0:
            s -= k*d[k]
            res += d[k]
        else:
            res += s // k
            break
    print(res)
##    print('--')
            
            
