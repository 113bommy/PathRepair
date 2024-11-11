from collections import Counter
n = int(input())
a = [int(_) for _ in input().split()]
f = Counter(a)
N = 10 ** 5 + 10
p = [0 for i in range(N)]
ans = Counter()
for i in range(2, N):
    if p[i]:
        continue
    for j in range(i, N, i):
        p[j] = 1
        ans[i] += f[j]
print(max(1, ans.most_common(1)[0][1]))
