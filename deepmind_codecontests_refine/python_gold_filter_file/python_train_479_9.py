n = int(input())
arr = [int(x) for x in input().split()]
suf = [int(0) for i in range(n + 1)]
for i in range(n - 1, -1, -1):
    suf[i] = suf[i + 1] + arr[i]
mp = dict()
for x in arr:
    if x in mp:
        mp[x] += 1
    else:
        mp[x] = 1
ans = 0
for i in range(n):
    ans += suf[i] - (n - i) * arr[i]
    if (arr[i] + 1) in mp:
        ans -= mp[arr[i] + 1]
    if (arr[i] - 1) in mp:
        ans += mp[arr[i] - 1]
    mp[arr[i]] -= 1
print(ans)