n, a, cnt = int(input()), list(map(int, input().split())), {}
for i in range(n):
    if a[i] not in cnt:
        cnt[a[i]] = [0, i, i]
    cnt[a[i]][0] += 1
    cnt[a[i]][2] = i
ans = [0, 0, 0]
for c, i, j in cnt.values():
    if c > ans[0] or (c == ans[0] and j - i < ans[2] - ans[1]):
        ans = [c, i, j]
print(ans[1] + 1, ans[2] + 1)
