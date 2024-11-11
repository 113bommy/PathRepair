N = int(input())

points = [list(map(int, input().split())) for _ in range(N)]

p = points[0][0]
q = points[0][1]
r = points[0][2]

points.sort(key=lambda x: x[2], reverse = True)

for i in range(0,101):
  for j in range(0,101):
    H= points[0][2] + abs(points[0][0] - i) + abs(points[0][1] - j)
    for x,y,z in points:
      if z != max(H - abs(x - i) - abs(y - j),0):
        break
    else:
      print(i,j,H)