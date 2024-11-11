import sys
import bisect
try:
	fin = open('in')
except:
	fin = sys.stdin
input = fin.readline

n, k = map(int, input().split())
r = list(map(int, input().split()))
l = [0] * (n - k + 1)
l[0] = sum(r[i] for i in range(k))
for i in range(1, n - k + 1):
	l[i] = l[i - 1] - r[i - 1] + r[i + k - 1]
t = [(-1, -1)] * (n - k + 1)
t[n - k] = (l[n - k], n - k)
for i in range(n - k - 1, -1, -1):
	t[i] = t[i + 1]
	if l[i] >= t[i][0]:
		t[i] = (l[i], i)
m = 0
x, y = -1, -1
for i in range(n - k * 2 + 1):
	if l[i] + t[i + k][0] > m:
		m = l[i] + t[i + k][0]
		x = i
		y = t[i + k][1]
print (x + 1, y + 1)