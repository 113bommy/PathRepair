
n = int(input())

for i in range(500000):
  if int(i*1.08) == n:
    print(i)
    break
else:
  print(":(")