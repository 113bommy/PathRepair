'''input
4
1 1 2 2 2 2 3 3
'''
n = int(input())
a = sorted(map(int, input().split()))
x1, y2 = a[0], a[-1]
x2, y1 = a[n-1], a[n]
m = (x1 - x2) * (y1 - y2)
x1, x2 = a[0], a[-1]
for i in range(1, n):
	y1, y2 = a[i], a[i+n-1]
	m = min(m, (x1 - x2) * (y1 - y2))
print(m)