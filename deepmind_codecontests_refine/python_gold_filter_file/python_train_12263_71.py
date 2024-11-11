n=int(input())
for i in range(n+1):
  if int(1.08*i)==n:
    print(i)
    exit()
print(':(')