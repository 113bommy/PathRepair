n = input()
n = int(n)

for _ in range(n):
  k = input()
  k = int(k)
  if k == 2:
    print(2)
  elif k % 2 == 0 and k > 2:
    print(0)
  else:
    print(1)
