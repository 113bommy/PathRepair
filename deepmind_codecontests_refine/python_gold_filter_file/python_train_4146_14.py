from collections import defaultdict
import bisect

N = int(input())
A = list(map(int, input().split()))
L2 = [1]
for i in range(40):
    L2.append(L2[-1]*2)
D = defaultdict(int)
for a in A:
    D[a] += 1
A.sort(reverse=True)
res = 0
for a in A:
    if D[a] < 1:
        continue
    D[a] -= 1
    beki2 = L2[bisect.bisect_right(L2, a)]
    j = beki2 - a
    if D[j] > 0:
        D[j] -= 1
        res += 1

print(res)
