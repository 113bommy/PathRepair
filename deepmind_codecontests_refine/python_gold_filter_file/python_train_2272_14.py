from collections import defaultdict
from itertools import permutations

n, c = map(int, input().split())
d = [list(map(int, input().split())) for _ in range(c)]
cmat = [list(map(int, input().split())) for _ in range(n)]

dcnt = [defaultdict(int) for _ in range(3)]
for i, ci in enumerate(cmat, 1):
    for j, cij in enumerate(ci, 1):
        mod = (i + j) % 3
        dcnt[mod][cij - 1] += 1

ans = 10 ** 9
for color in permutations(range(c), 3):
    if len(set(color)) == 3:
        tmp = 0
        for i, cnt in enumerate(dcnt):
            tmp += sum(d[k][color[i]] * cnt[k] for k in cnt)
        ans = min(ans, tmp)
print(ans)
