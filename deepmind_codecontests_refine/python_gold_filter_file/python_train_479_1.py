n = int(input())
a = [int(x) for x in input().split()]
s = 0
total = 0
cnt = {}
for i in reversed(range(n)):
    s += a[i]
    if a[i] not in cnt:
        cnt[a[i]] = 0
    cnt[a[i]] += 1
    total += s - (n - i) * a[i]
    if a[i] + 1 in cnt:
        total -= cnt[a[i] + 1]
    if a[i] - 1 in cnt:
        total += cnt[a[i] - 1]
print(total)
