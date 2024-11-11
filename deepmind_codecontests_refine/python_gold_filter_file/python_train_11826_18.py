n = int(input())
a = list(map(int, input().split()))

a.sort()

x = 2000000009
for i in range(n - 1):
  x = min(x, a[i + 1] - a[i])
  
ans = 0
for i in range(n - 1):
  if(a[i + 1] - a[i] == x):
    ans += 1

print(x, ans)

  
