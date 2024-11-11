
n = int(input())

cities = [int(c) for c in input().split(" ")]

for i in range(len(cities)):
  if i == 0:
    print("%d %d" % (abs(cities[1] - cities[0]), abs(cities[-1] - cities[0])))
  elif i == len(cities) - 1:
    print("%d %d" % (abs(cities[-2] - cities[-1]), abs(cities[0] - cities[-1])))
  elif abs(cities[0] - cities[i]) > abs(cities[-1] - cities[i]):
    if abs(cities[i - 1] - cities[i]) < abs(cities[i + 1] - cities[i]):
      print("%d %d" % (abs(cities[i - 1] - cities[i]), abs(cities[0] - cities[i])))
    else:
      print("%d %d" % (abs(cities[i + 1] - cities[i]), abs(cities[0] - cities[i])))
  else:
    if abs(cities[i - 1] - cities[i]) < abs(cities[i + 1] - cities[i]):
      print("%d %d" % (abs(cities[i - 1] - cities[i]), abs(cities[-1] - cities[i])))
    else:
      print("%d %d" % (abs(cities[i + 1] - cities[i]), abs(cities[-1] - cities[i])))