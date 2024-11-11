n, s = map(int, input().split())
v = sorted(list(map(int, input().split())))

if sum(v) < s:
    print(-1)
else:
    remainder = (sum(v) - s) // n
    print(min(v[0], remainder))
