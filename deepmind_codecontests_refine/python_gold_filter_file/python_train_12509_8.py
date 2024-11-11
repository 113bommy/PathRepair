from sys import stdin
from bisect import bisect_right
inp = lambda : stdin.readline().strip()

n = int(inp())
a =[int(x) for x in inp().split()]
v = {8:4,15:8,16:15,23:16,42:23}
d = {4:0,8:0,15:0,16:0,23:0,42:0}
for i in a:
    if i == 4 or d[v[i]] > d[i]:
        d[i] += 1

minimum = 10**9
for i in d.values():
    minimum = min(i,minimum)
print(len(a)-minimum*6)
