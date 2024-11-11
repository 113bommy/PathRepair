n, f = map(int, input().split())

ks = []
ls = []
diff = []
for _ in range(n):
    k, l = map(int, input().split())
    ks.append(k)
    ls.append(l)
    diff.append(min(l, 2*k) - min(l, k))

sorted_diff = [i for i, _ in sorted(list(enumerate(diff)),
                                    reverse=True,
                                    key=lambda x: x[1])]
for i in range(f):
    ks[sorted_diff[i]] *= 2

ans = sum(min(i, j) for i, j in zip(ks, ls))

print(ans)
