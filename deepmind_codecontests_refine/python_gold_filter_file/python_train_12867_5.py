from math import inf

n, x = map(int, input().split())

a = []
best = [inf for i in range(2 * (10**5) + 1)]
ans = inf

for i in range(n):
    l, r, cost = map(int, input().split())

    a.append((l, cost, r-l+1, True))
    a.append((r, cost, r-l+1, False))

a.sort(key=lambda element: 10 * element[0] + 1 - int(element[3]))

for item in a:
    if item[3] and x > item[2]:
        ans = min(ans, item[1] + best[x - item[2]])

    if not item[3]:
        best[item[2]] = min(best[item[2]], item[1])


print(ans if ans != inf else -1)
