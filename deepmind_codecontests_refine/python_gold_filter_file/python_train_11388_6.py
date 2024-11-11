n = int(input())
a = list(map(int, input().split()))
mx = 0
for x in a:
    mx = max(mx, a.count(x))
if mx <= n // 2 +n % 2:
  print("YES")
else:
  print("NO")