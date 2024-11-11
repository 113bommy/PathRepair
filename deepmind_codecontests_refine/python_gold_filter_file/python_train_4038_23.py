n, m, x =map(int,input().split())
s = [list(map(int, input().split())) for _ in range(n)]
ans = 10000000
for i in range(2 ** n):
  bag = [0]*(m+1)
  for j in range(n):
    if ((i>>j)&1):
        for _ in range(m+1):
          bag[_] += s[j][_]
  ##print(bag)
  if (min(bag[1:]) >= x and ans > bag[0]):
    ans = bag[0]
    
if ans == 10000000:
  print("-1")
else:
  print(ans)
    
    