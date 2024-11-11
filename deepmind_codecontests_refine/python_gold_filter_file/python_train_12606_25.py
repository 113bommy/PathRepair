n, m = map(int, input().split())
a, b = [], []
for _ in range(n):
    ab = list(map(int, input().split()))
    a.append(ab[0])
    b.append(ab[1])

diffs = sorted([a - b for a, b in zip(a, b)], reverse=True)

ans = 0
s = sum(a)
for d in diffs + [0]:
    if s <= m:
        print(ans)
        exit(0)
    s -= d
    ans += 1

print(-1)
