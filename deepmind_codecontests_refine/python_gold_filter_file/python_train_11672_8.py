n, m, k, l = map(int, input().split(' '))

cat = (k + l) // m + (1 if (k + l) % m else 0)

if(cat * m > n):
  print(-1)
else:
  print(cat)
