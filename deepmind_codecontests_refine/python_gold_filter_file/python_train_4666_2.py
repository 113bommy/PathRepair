a = [0]*5
for i in range(3):
  x,y = map(int,input().split())
  a[x] += 1
  a[y] += 1
if sorted(a) == [0,1,1,2,2]:
  print("YES")
else:
  print("NO")