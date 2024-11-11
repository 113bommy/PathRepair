n=int(input())

for i in range(n):
  for j in range(n):
    if i*4+j*7==n:
      print('Yes')
      exit()
print('No')