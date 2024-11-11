n, m = map(int, input().split())
prime = 1000003;
m -= n - 1
print(prime, prime)
for i in range(n - 1):
  print(i + 1, i + 2, 1 if i else prime - n + 2)
for i in range(n):
  for j in range(i + 2, n):
    if not m: 
      break
    print(i + 1, j + 1, 10 * prime)
    m -= 1
