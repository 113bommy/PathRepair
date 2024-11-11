n=int(input())
for x in range(60000):
  if int(x*1.08)==n:
    print(x)
    exit()
print(":(")