import sys
input = sys.stdin.readline
def getInt(): return int(input())
def getVars(): return map(int, input().split())
def getList(): return list(map(int, input().split()))
def getStr(): return input().strip()
## -------------------------------

t = getInt()
for _ in range(t):
    a, b, n, m = getVars()
    res = 'No'
    if a + b >= n + m:
        if min(a, b) >= m:
            res = 'Yes'
    print(res)
        
