m,d = map(int, input().split())
res = 0
for i in range(1,m+1):
  for j in range(1,d+1):
    if j >= 22 and j % 10 >= 2 and int(str(j)[0]) * int(str(j)[1]) == i:
      res += 1
print(res)
