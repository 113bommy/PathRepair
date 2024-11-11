from math import sqrt

r,h = map (int, input().split())
count = h // r * 2
h -= h // r * r
if h >= sqrt(3) / 2 * r:
  count += 3
elif h >= r / 2:
  count += 2
else:
  count += 1
print (count)
