n = int(input())
a = list(map(int, input().split()))
ans = 1
tmp = a[0]
for i in a:
  if i < tmp:
    tmp = i
    ans += 1
print(ans)