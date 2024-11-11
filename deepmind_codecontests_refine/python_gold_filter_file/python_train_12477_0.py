x=int(input())
for i in range(100000):
  if i * (i+1) >= 2 * x:
    print(i)
    quit()