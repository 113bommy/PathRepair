ans = []
for t in range(int(input())):
    n = int(input()); a = list(map(int, input().split()))
    if len(set(a)) == 1: ans += [['NO']]
    else:
        ans += [['YES']]; bad = []
        for i in range(1, n):
            if a[i] != a[0]: ans += [(1, i + 1)]
            else: bad += [i + 1]
        for i in range(n - 1, -1, -1):
            if a[i] != a[0]:
                for el in bad: ans += [(i + 1, el)]
                break     
[print(*i) for i in ans]