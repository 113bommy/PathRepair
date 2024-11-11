n,  m = map(int, input().split())
np = [input() for _ in range(n)]
mp = [input() for _ in range(m)]
for i in range(n-m+1):
  for j in range(n-m+1):
    f = True
    for k in range(m):
      if np[i+k][j:j+m] != mp[k]:
        f = False
    if f:
      print("Yes")
      exit(0)
else:
  print("No")
