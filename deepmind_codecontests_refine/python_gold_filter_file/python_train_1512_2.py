import sys

def get_array(): return list(map(int, sys.stdin.readline().split()))
def get_ints(): return map(int, sys.stdin.readline().split())
def input(): return sys.stdin.readline().strip('\n')

n = int(input())
l = get_array()

l.sort()
k = sum(l)
nw = [k//n]*n

k %= n

for i in range(k):
    nw[i] += 1

nw = nw[::-1]
ans = 0
for i in range(n):
    ans += abs(l[i]-nw[i])

print(ans//2)
