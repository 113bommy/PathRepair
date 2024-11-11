points = []
for _ in range(int(input())):
  points.append(list(map(int,input().split())))
d = {'1st': [], '2nd': []}
for point in points:
  if (point[0] >= 0 and point[1] >= 0) or (point[0] >= 0 and point[1] <= 0):
    d['1st'].append(point)
  if (point[0] <= 0 and point[1] <= 0) or (point[0] <= 0 and point[1] >= 0):
    d['2nd'].append(point)
if (len(d['1st']) == 1) or (len(d['2nd']) == 1) or (len(d['1st']) == 0) or (len(d['2nd']) == 0):
  print("Yes")
else:
  print("No")