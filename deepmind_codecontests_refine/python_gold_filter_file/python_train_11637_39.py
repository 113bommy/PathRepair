import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

c = [0] * (n + 1)
d = [0] * (n + 1)
for i in range(n):
    c[a[i]] += 1
    d[b[i]] += 1
# 鳩の巣原理
# どんなに頑張っても1個以上重なる
for i in range(n + 1):
    if c[i] + d[i] > n:
        print('No')
        sys.exit(0)

import itertools
c = list(itertools.accumulate(c))
d = list(itertools.accumulate(d))

max_gap = 0
for i in range(1, n + 1):
    max_gap = max(max_gap, c[i] - d[i-1])

ans = [0] * n
for i in range(n):
    ans[(i + max_gap) % n] = str(b[i])

print('Yes')
print(' '.join(ans))
