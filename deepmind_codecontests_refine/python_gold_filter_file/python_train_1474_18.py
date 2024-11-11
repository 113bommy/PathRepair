import math
import sys

#imgur.com/Pkt7iIf.png

def ii(): return int(input())
def mi(): return map(int, input().split())
def li(): return list(map(int, input().split()))

MAX = 2*10**5 + 7
n = ii()
d = sorted(li())
d.append(MAX-1)
used = [0]*MAX
f = []
s = []

for i in range(n):
    if used[d[i]] > 1:
        exit(print("NO"))
    used[d[i]] += 1

    if d[i] == d[i+1]:
        f.append(d[i])
    else:
        s.append(d[i])

print("YES")
print(len(f))
print(" ".join([str(x) for x in f]))
print(len(s))
print(" ".join([str(x) for x in reversed(s)]))
