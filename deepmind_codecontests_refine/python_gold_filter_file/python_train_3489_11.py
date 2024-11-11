def main():
	n = int(input())
	points = [None] * n
	for i in range(n):
		(x, y) = (int(x) for x in input().split())
		points[i] = (x, y)
	L = solver(points)
	print(*L)

def solver(points):
	S = set(points)
	# find 3 points that are not collinear
	D = {points[i]: i + 1 for i in range(len(points))}
	(point1, point2, point3) = find3NonCollinearPoints(points)
	S.remove(point1)
	S.remove(point2)
	S.remove(point3)
	while len(S) != 0:
		point = S.pop()
		if contains(point1, point2, point3, point):
			#print(point1, point2, point3, point)
			if areCollinear(point1, point2, point):
				point2 = point
			else:
				point3 = point
			# elif areCollinear(point2, point3, point):
			# 	point3 = point
			# elif areCollinear(point1, point3, point):
			# 	point3 = point
			# else:
			# 	point1 = point
	#print(point1, point2, point3)
	return (D[point1], D[point2], D[point3])


def find3NonCollinearPoints(points):
	point1 = None
	point2 = None
	point3 = None
	for i in range(len(points)):
		point1 = points[i]
		for j in range(i + 1, len(points)):
			point2 = points[j]
			for k in range(j + 1, len(points)):
				point3 = points[k]
				#print(i, j, k)
				if not areCollinear(point1, point2, point3):
					return (point1, point2, point3)
	return None

# ax + by = c
def toLine(point1, point2):
	(x1, y1) = point1
	(x2, y2) = point2
	if x1 == x2:
		if y1 == y2:
			assert(False)
		else:
			return (1, 0, x1)
	else:
		a = (y2 - y1) / (x1 - x2)
		c = a * x1 + y1
		return (a, 1, c)

def onSameSide(line, point1, point2):
	(a, b, c) = line
	(x1, y1) = point1
	(x2, y2) = point2
	if a * x1 + b * y1 >= c and a * x2 + b * y2 >= c:
		return True
	elif a * x1 + b * y1 <= c and a * x2 + b * y2 <= c:
		return True
	else:
		return False

def contains(point1, point2, point3, point):
	line1 = toLine(point2, point3)
	line2 = toLine(point1, point3)
	line3 = toLine(point1, point2)
	#print(line1, line2, line3)
	return onSameSide(line1, point1, point) and \
	onSameSide(line2, point2, point) and \
	onSameSide(line3, point3, point)

def almostEqual(x, y):
	return abs(x - y) < 10**-16

def linesEqual(line1, line2):
	for i in range(len(line1)):
		if not almostEqual(line1[i], line2[i]):
			return False
	return True

def areCollinear(point1, point2, point3):
	line1 = toLine(point2, point3)
	line2 = toLine(point1, point3)
	#print(line1, line2)
	return linesEqual(line1, line2)

main()
#print(line((3, 2), (2, 3)))

#print(onSameSide((1, 1, 5), (2, 2), (3, 3)))

#print(areCollinear((0, 1), (0, 2), (0, 4)))
#print(areCollinear((1, 0), (2, 0), (4, 0)))

#print(contains((0, 0), (1, 1), (2, 0), (0, 2)))
#L = [1, 2, 3]
#S = set(L)
#print(S)
#print(areCollinear((0, 0), (1, 1), (2, 0)))
#print(solver([(0, 0), (0, 2), (2, 2), (1, 1),  (2, 0)]))

L = [(999999999, 1),
(999999998, 1),
(999999997, 1),
(1000000000, 1),
(999999996, 1),
(999999995, 1),
(999999994, 1),
(999999992, 1),
(999999993, 1),
(0, 0)]
#print(areCollinear((999999999, 1), (999999998, 1), (0, 0)))
#print(solver(L))
