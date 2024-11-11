n = int(input())
if n % 2:
  print(0)
  quit()
ans = 0
for i in range(1,36):
  ans += (n // (2 * 5 ** i))
print(ans)