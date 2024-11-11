#!usr/bin/env python3
from collections import defaultdict
from heapq import heappush, heappop
import sys
import math
import bisect
import random
def LI(): return list(map(int, sys.stdin.readline().split()))
def I(): return int(sys.stdin.readline())
def LS(): return sys.stdin.readline().split()
def S(): return list(sys.stdin.readline())
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def LSR(n): return [LS() for i in range(n)]
mod = 1000000007

#A
"""
n,k = LI()
if 2*(k-1) < n:
    print("YES")
else:
    print("NO")
"""

#B
"""
c = LIR(3)
v = [[] for i in range(4)]
for i in range(3):
    c[i][0] -= 1
    c[i][1] -= 1
    v[c[i][0]].append(c[i][1])
    v[c[i][1]].append(c[i][0])

for i in range(4):
    li = [True for i in range(4)]
    li[i] = False
    q = [i]
    c = 0
    while q:
        x = q.pop(-1)
        k = 0
        for j in v[x]:
            if li[j]:
                li[j] = False
                q.append(j)
                if k == 0:
                    c += 1
                    k += 1
    if c == 3:
        print("YES")
        quit()
print("NO")
"""

#C
"""
k,a,b = LI()
if k <= a:
    print(k+1)
else:
    if b-a < 3:
        print(k+1)
    else:
        ans = a+((k-a+1)//2)*(b-a)+(k-a+1)%2
        print(ans)
"""

#D

#E
"""
n,m = LI()
a = LIR(n)
a.sort()
a = a[::-1]
for i in range(n):
    for j in range(i+1,n):
        s = 0
        while a[i][s] == 0 and s < m-1:s+=1
        if s < m and a[i][s] != 0:
            if a[j][s] > 0:
                for k in range(s,m):
                    a[j][k] -= 1*a[i][k]
                    a[j][k] = abs(a[j][k])
r = 0
for i in range(n):
    if sum(a[i]) > 0:r += 1
print((pow(2,n+m-1)-pow(2,n-r+m-1))%998244353)
"""

#F
mod = 998244353
s = list(sys.stdin.readline().strip())
n = len(s)
dp = [[0 for i in range(2*n+1)] for j in range(2*n+1)]
r = [0 for i in range(n)]
b = [0 for i in range(n)]
for i in range(n):
    b[i] = int(s[i])
    r[i] = 2-b[i]
for i in range(n-1):
    r[i+1] += r[i]
    b[i+1] += b[i]
r.insert(0,0)
b.insert(0,0)
if r[1] > 0:
    dp[1][1] = 1
for i in range(1,2*n+1):
    if b[min(i,n)] < i:break
    if b[min(i,n)] >= i:dp[i][0] = 1
for i in range(2,n+1):
    for j in range(1,2*n+1):
        if r[i] >= j:
            dp[i][j] += dp[i-1][j-1]
            dp[i][j] %= mod
        if b[i] >= i-j:
            dp[i][j] += dp[i-1][j]
            dp[i][j] %= mod
for i in range(n+1,2*n+1):
    for j in range(1,2*n+1):
        if r[n] >= j:
            dp[i][j] += dp[i-1][j-1]
            dp[i][j] %= mod
        if b[n] >= i-j:
            dp[i][j] += dp[i-1][j]
            dp[i][j] %= mod

print(dp[2*n][r[-1]])

#G

#H

#I

#J

#K

#L

#M

#N

#O

#P

#Q

#R

#S

#T
