n=int(input())
for i in range(1,50001):
  if int(i*1.08) == n:
    print(i)
    break
else:
  print(':(')