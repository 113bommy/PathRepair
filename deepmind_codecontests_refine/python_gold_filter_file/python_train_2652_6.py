m, t, r = map(int, input().split())
w = list(map(int, input().split()))
w.sort()
cur = set()
cur1 = set()
cnt = 0

for i in range(m):
    for j in cur:
        if j + t >= w[i]:
            cur1.add(j)
    cur = set()
    for j in cur1:
        cur.add(j)
    cur1 = set()

    j = w[i] - 1
    while j >= w[i] - t and len(cur) < r:
        if not j in cur:
            cur.add(j)
            cnt += 1
        j -= 1

    if len(cur) < r:
        print(-1)
        exit()

print(cnt)