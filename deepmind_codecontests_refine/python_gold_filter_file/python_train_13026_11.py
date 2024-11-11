n, k = map(int, input().split())
values = list(map(int, input().split()))
coloring = [0] * n
IS_POSSIBLE = True
c = 0
for v in set(values):
    s = set()
    for i in range(n):
        if values[i] == v:
            c += 1
            if c in s:
                IS_POSSIBLE = False
                break
            coloring[i] = c
            s.add(c)
        if c >= k:
            c = 0
    if not IS_POSSIBLE:
        break

if IS_POSSIBLE:
    print("YES")
    print(' '.join(map(str, coloring)))
else:
    print("NO")
