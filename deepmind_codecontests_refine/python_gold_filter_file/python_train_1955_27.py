import sys
def input():
	return sys.stdin.readline()[:-1]

n = int(input())
cnt = [[0 for _ in range(20)] for _ in range(20)]
ans = 0
for _ in range(n):
	a = input()
	x, y = 0, 0
	if "." in a:
		i = len(a)-1
		while a[i] != ".":
			i -= 1
			x, y = x-1, y-1
		b = int(a[:i] + a[i+1:])
	else:
		b = int(a)
	#print(b)
	while b%2 == 0 and x < 9:
		x += 1
		b //= 2
	while b%5 == 0 and y < 9:
		y += 1
		b //= 5
	#print(x, y)
	x, y = x+9, y+9
	for i in range(18-x, 20):
		for j in range(18-y, 20):
			ans += cnt[i][j]
	cnt[x][y] += 1
print(ans)