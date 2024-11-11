n, m, k = map(int, input().split())
ans = []
i = j = 1
while i <= n:
    if j < 1 or j > m:
        i += 1
        j += [-1, 1][i % 2]
    if i > n:
        break
    ans.append("{} {}".format(i, j))
    j += [-1, 1][i % 2]
div = len(ans) // k
i = -1
for i in range(k - 1):
    print(div, " ".join(ans[i * div: (i + 1) * div]))
ans = ans[(i + 1) * div:]
print(len(ans), " ".join(ans))