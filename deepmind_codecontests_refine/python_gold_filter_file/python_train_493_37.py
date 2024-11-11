n = int(input())
res = 0
for a in range(1, n):
  res += ((n - 1) // a)
print(res)