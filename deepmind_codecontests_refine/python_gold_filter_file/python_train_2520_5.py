from math import sqrt
def distance(x1, y1 , x2, y2):
	return sqrt((x2-x1)**2 + (y2-y1)**2)

n, k = map(int, input().split())
li = []
for i in range(n):
	li.append(list(map(int, input().split())))
res = 0
for i in range(1, n):
	res += distance(li[i][0], li[i][1], li[i-1][0], li[i-1][1])/50
print(res*k)