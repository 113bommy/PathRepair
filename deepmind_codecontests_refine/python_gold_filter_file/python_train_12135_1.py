n, m = map(int, input().split())
a = [input().split() for _ in range(n)]
for l in range(m):
    for r in range(l, m):
        for s in a:
            s1 = s.copy()
            s1[l], s1[r] = s1[r], s1[l]
            if sum(int(s1[i]) != i + 1 for i in range(m)) > 2:
                break
        else:
            print('YES')
            exit()
print('NO')