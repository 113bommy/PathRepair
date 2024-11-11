# coding: utf-8
# Your code here!
import sys
read = sys.stdin.read
readline = sys.stdin.readline

n,z,w = map(int, readline().split())
a = [w]+[*map(int, readline().split())]
n += 1

INF = 1<<30
dp0 = [-INF]*n
dp1 = [INF]*n

dp0[-1] = dp1[-1] = abs(a[-1]-a[-2])
for i in range(n-2,0,-1):
    dp0[i] = max(abs(a[-1]-a[i-1]),max(dp1[i+1:]))
    dp1[i] = min(abs(a[-1]-a[i-1]),min(dp0[i+1:]))

print(dp0[1])

#print(a)
#print(dp0)
#print(dp1)



