n, k = map(int, input().split())
cnt = {}
for c in input():
  if c in cnt:
    cnt[c] += 1
  else:
    cnt[c] = 1
ans = "YES"
for x in cnt.values():
  if x > k:
    ans = "NO"
print(ans)