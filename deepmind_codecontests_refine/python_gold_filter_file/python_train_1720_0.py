n = int(input())
l = 0
if n == 1:
  print(1)
  exit()
for i in range(1, 100000000):
  if (i +2) * (i+1)//2 == n:
    print(i+1)
    exit()
  elif (i +2) * (i+1)//2 > n:
    n -= (i+1)*i//2
    break
print(n)