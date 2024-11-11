a, b, k = map(int, input().split())

r = range(a, b + 1)
r = list(set(r[:k]) | set(r[-k:]))
r.sort()

for _r in r:
    print(_r)