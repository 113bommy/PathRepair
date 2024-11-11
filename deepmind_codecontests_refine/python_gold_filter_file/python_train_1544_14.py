import sys
stdin = sys.stdin

def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

from itertools import accumulate

n,x = li()
a = list(li())

# 係数リスト
coef = [5] + [2*i + 5 for i in range(n+1)]

a = a[::-1]
a_cum = [0] + list(accumulate(a))

ans = float("inf")
# 往復回数決め打ち
for k in range(1,n+1):
    cost = (n+k) * x
    i = 0
    while i*k <= n:
        cost += coef[i]*(a_cum[min((i+1)*k, n)] - a_cum[i*k])
        i += 1

    ans = min(ans, cost)
    
print(ans)