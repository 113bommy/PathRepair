n = int(input())
ans = 0
for i in range(n):
  x,y = input().split()
  ans += (float(x) if y == "JPY" else float(x)*380000)
print(ans)
