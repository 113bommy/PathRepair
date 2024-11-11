import sys
import math
input = sys.stdin.readline
sys.setrecursionlimit(10**7)
from collections import defaultdict

MOD = 10**9+7
N = int(input())
dic = defaultdict(int)
zero = 0
for i in range(N):
    a, b = map(int, input().split())
    if b < 0:
        a = -a
        b = -b
    if a == 0 and b == 0:
        zero += 1
        continue
    elif a == 0:
        b = 1
    elif b == 0:
        a = 1
    g = math.gcd(a, b)
    a //= g
    b //= g
    dic[a,b] += 1
done = set()
ans = 1
for a,b in dic:
    k = (a, b)
    if k in done: continue
    c, d = -b, a
    if d <= 0:
        c = -c
        d = -d
    rk = (c, d)
    done.add(k)
    done.add(rk)
    c = pow(2, dic[k], MOD)-1
    if rk in dic:
        c += pow(2, dic[rk], MOD)-1
    c += 1
    ans *= c
    ans %= MOD
print((ans+zero-1)%MOD)
