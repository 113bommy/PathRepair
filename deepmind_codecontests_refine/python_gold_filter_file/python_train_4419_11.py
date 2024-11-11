from bisect import bisect_right

R = lambda: map(int, input().split())
n = int(input())
reqs = []
for i in range(n):
    num, c = R()
    reqs.append((num, c, i))
t = int(input())
tables = sorted((table, i) for i, table in enumerate(R()))
reqs.sort(key=lambda x: (-x[1],x[0]))

sol, tc = dict(), 0
for r in reqs:
    i = bisect_right(tables, (r[0], -1))
    if i < len(tables):
        sol[r[2]] = tables[i][1]
        tc += r[1]
        tables = tables[:i] + tables[i + 1:]
print(len(sol), tc)
for k in sol.keys():
    print(k + 1, sol[k] + 1)