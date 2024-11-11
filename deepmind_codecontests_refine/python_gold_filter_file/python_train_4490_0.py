from collections import defaultdict
from itertools import accumulate

n, m = [int(x) for x in input().split()]
dt = defaultdict(lambda : [])

for i in range(n):
    sub, lvl = [int(x) for x in input().split()]
    dt[sub].append(lvl)

for key in dt.keys():
    dt[key].sort(reverse=True)

ans = [0 for i in range(n+1)]

# print(dt)
for key in dt.keys():
    vals = dt[key]
    prefix = list(accumulate(vals))
    # print(vals, prefix)
    for l in range(len(vals)):
        if prefix[l] >= 0:
            ans[l+1] += prefix[l]
        else:
            break

print(max(ans))
