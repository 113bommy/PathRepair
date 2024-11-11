from sys import stdin
from sys import setrecursionlimit as SRL; SRL(10**7)
rd = stdin.readline
rrd = lambda: map(int, rd().strip().split())


n = int(rd())
a = list(rrd())

bit = [0] * (n+10)


def get(x):
    tot = 0
    while x:
        tot += bit[x]
        x -= x&(-x)
    return tot

def ins(x):
    while x<=(n+1):
        bit[x] += 1
        x += x&(-x)

b = []
preans = 0
for i,v in enumerate(a):
    if v > i:
        preans += 1
    b.append([i+1,v])

b.sort(key=lambda x:x[1])

ans = 0
i = 0

for x in b:
    while i<n and i < x[1]:
        ins(a[i])
        i += 1
    ans += i - get(x[0] - 1)


print((ans-preans)//2)