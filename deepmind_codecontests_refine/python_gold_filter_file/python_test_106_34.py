for i in range(int(input())):
  res = []
  n = int(input())
  if n==1:
    res.append(1)
  else:
    for i in range(2, n+2):
      res.append(i)
    for i in range(1, len(res)):
      while (res[i]%res[i-1])==0:
        res[i] += 1
  print(*res)