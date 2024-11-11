import itertools

n, m = map(int, input().split())
A = [i + 1 for i in range(n)]

perms = list(itertools.permutations(A))
d = []
for x in perms:
    s = 0
    for i in range(n):
        for j in range(i + 1, n):
            s += min(x[i:(j + 1)])
    d.append((s, x))
mx = max(d)[0]
ans = []
for x in d:
    if x[0] == mx:
        ans.append(x[1])
ans.sort()
print(' '.join(str(x) for x in ans[m - 1]))
