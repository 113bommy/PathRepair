n = int(input())
if n % 2 == 1:
  print(-1)
  exit(0)

for i in range(n // 2):
  print(i * 2 + 2, i * 2+ 1, end = ' ')
