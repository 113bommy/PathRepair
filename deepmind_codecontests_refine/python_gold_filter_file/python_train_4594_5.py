import sys
import math
from collections import defaultdict
import heapq

def dist(a, b, c, d):
	X = (a - c) ** 2
	Y = (b - d) ** 2
	return math.sqrt(X + Y)

a, b, c = map(int, sys.stdin.readline().split())
x1, y1, x2, y2 = map(int, sys.stdin.readline().split())

if a == 0 or b == 0:
	res = abs(x1 - x2) + abs(y1 - y2)
	print(res)
	sys.exit()

ans = abs(x1 - x2) + abs(y1 - y2)

x11, y11 = x1, -(c + a * x1) / b
x12, y12 = -(c + b * y1) / a, y1

x21, y21 = x2, -(c + a * x2) / b
x22, y22 = -(c + b * y2) / a, y2


dis = abs(x11 - x1) + abs(y11 - y1) + abs(x2 - x21) + abs(y2 - y21) + dist(x11, y11, x21, y21)
ans = min(ans, dis)

dis = abs(x11 - x1) + abs(y11 - y1) + abs(x2 - x22) + abs(y2 - y22) + dist(x11, y11, x22, y22)
ans = min(ans, dis)

dis = abs(x12 - x1) + abs(y12 - y1) + abs(x2 - x21) + abs(y2 - y21) + dist(x12, y12, x21, y21)
ans = min(ans, dis)

dis = abs(x12 - x1) + abs(y12 - y1) + abs(x2 - x22) + abs(y2 - y22) + dist(x12, y12, x22, y22)
ans = min(ans, dis)

print(ans)