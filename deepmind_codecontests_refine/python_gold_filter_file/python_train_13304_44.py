L,R = map(int,input().split())
if (R-L >= 2019):
  print(0)
else:
  res = 2019
  for i in range(L,R):
    for j in range(i+1,R+1):
      res = min(res,(i*j)%2019)
  print(res)