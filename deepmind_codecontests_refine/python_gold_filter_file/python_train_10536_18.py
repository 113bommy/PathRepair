from sys import stdin, stdout
from math import floor, gcd, fabs, factorial, fmod, sqrt, inf, log
from collections import defaultdict as dd, deque
from heapq import merge, heapify, heappop, heappush, nsmallest
from bisect import bisect_left as bl, bisect_right as br, bisect
        
mod = pow(10, 9) + 7
mod2 = 998244353
        
def inp(): return stdin.readline().strip()
def iinp(): return int(inp())
def out(var, end="\n"): stdout.write(str(var)+"\n")
def outa(*var, end="\n"): stdout.write(' '.join(map(str, var)) + end)
def lmp(): return list(mp())
def mp(): return map(int, inp().split())
def smp(): return map(str, inp().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(m, val) for j in range(n)]
def remadd(x, y): return 1 if x%y else 0
def ceil(a,b): return (a+b-1)//b
  
def isprime(x):
    if x<=1: return False
    if x in (2, 3): return True
    if x%2 == 0: return False
    for i in range(3, int(sqrt(x))+1, 2):
        if x%i == 0: return False
    return True
 
for _ in range(int(inp())):
    s = inp()
    u = s.count('U')
    d = s.count('D')
    r = s.count('R')
    l = s.count('L')
    # ans = max(u, d)-min(u, d)
    # ans += max(l, r)-min(l, r)
    u, r = min(u, d), min(l, r)
    if u==0 and r==0:
        print(0)
    elif u==0:
        print(2)
        print('LR')
    elif r==0:
        print(2)
        print('UD')
    else: 
        print(2*(u+r))
        print('U'*u+'R'*r+'D'*u+'L'*r)