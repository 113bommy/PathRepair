import math

def dist(x0, y0, x1, y1):
    return math.sqrt(math.pow((x1-x0), 2) + math.pow((y1-y0), 2))

tmp = input().split()
n, k = int(tmp[0]), float(tmp[1])


list_l = []

tmp = input().split()
list_l.append((float(tmp[0]), float(tmp[1])))

dist_sum = 0

for i in range(1, n):
	tmp = input().split()
	list_l.append((float(tmp[0]), float(tmp[1])))

	dist_sum += dist(list_l[i-1][0], list_l[i-1][1], list_l[i][0], list_l[i][1])


dist_sum /= 50
dist_sum *= k

print(dist_sum)




