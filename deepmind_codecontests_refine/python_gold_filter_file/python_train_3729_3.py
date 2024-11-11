import bisect
import collections

N, M = map(int, input().split())
PM = [[int(j) for j in input().split()] for i in range(M)]
A = collections.defaultdict(list)
for x, y in sorted(PM):
    A[x] += [y]
for x, y in PM:
    z = bisect.bisect(A[x], y)
    print('%06d%06d'%(x,z))