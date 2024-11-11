import sys

sys.setrecursionlimit(10**5)
int1 = lambda x: int(x)-1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.buffer.readline())
def MI(): return map(int, sys.stdin.buffer.readline().split())
def LI(): return list(map(int, sys.stdin.buffer.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def BI(): return sys.stdin.buffer.readline().rstrip()
def SI(): return sys.stdin.buffer.readline().rstrip().decode()
inf = 10**16
md = 10**9+7
# md = 998244353

from bisect import *
from math import gcd
import typing

def inv_gcd(a, b):
    a %= b
    if a == 0: return b, 0
    s, t = b, a
    m0, m1 = 0, 1
    while t:
        u = s//t
        s -= t*u
        m0 -= m1*u
        s, t = t, s
        m0, m1 = m1, m0
    if m0 < 0: m0 += b//s
    return s, m0

# 複数の「mで割ったらr余る」という条件を満たすxをmod zで返す
# 返り値 x,z（解なしの場合は0,0）
def crt(r: typing.List[int], m: typing.List[int]) -> typing.Tuple[int, int]:
    assert len(r) == len(m)

    n = len(r)
    r0, m0 = 0, 1
    for i in range(n):
        assert 1 <= m[i]
        r1 = r[i]%m[i]
        m1 = m[i]
        if m0 < m1:
            r0, r1 = r1, r0
            m0, m1 = m1, m0
        if m0%m1 == 0:
            if r0%m1 != r1: return 0, 0
            continue

        g, im = inv_gcd(m0, m1)

        u1 = m1//g
        if (r1-r0)%g: return 0, 0

        x = (r1-r0)//g%u1*im%u1

        r0 += x*m0
        m0 *= u1
        if r0 < 0: r0 += m0

    return r0, m0

N,M,k=MI()

# from random import sample
# aa=sample(list(range(1,N*2)),N)
# bb=sample(list(range(1,M*2)),M)

aa=LI()
bb=LI()
atoi={a:i for i,a in enumerate(aa)}
g=gcd(N,M)
lcm=N*M//g
# print(lcm)

ss=[]
for j,b in enumerate(bb):
    if b not in atoi:continue
    i=atoi[b]
    # if abs(i-j)%g:continue
    r,t=crt([atoi[b],j],[N,M])
    if t==0:continue
    ss.append(r)
# print(ss)
tot=lcm-len(ss)
# print(tot)
ss.sort()
p,k=divmod(k,tot)
if k==0:
    p-=1
    k+=tot
# print(p,k)
ans=p*lcm

# x>=k
def ok(m):
    i=bisect_left(ss,m)
    return m-i>=k

l,r=0,lcm+5
while l+1<r:
    m=(l+r)//2
    if ok(m):r=m
    else:l=m

print(ans+r)
