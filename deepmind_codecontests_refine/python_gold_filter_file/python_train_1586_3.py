def main():
	n = int(input())
	for i in range(n):
		f()

def f():
	n, m = map(int, input().split()) #size a, size p
	b = list(map(int, input().split()))
	p = list(map(lambda x: int(x) - 1, input().split()))
	a = [[i, False] for i in b]
	for i in range(m):
		a[p[i]][1] = True

	for i in range(n-1, -1, -1):
		max_ = 0
		index_ = -1
		for j in range(i + 1):
			if a[j][0] >= max_:
				max_ = a[j][0]
				index_ = j
			# print("i={}, j={}, max={}, index={}".format(i, j, max_, index_))
		flag = True
		for x in range(index_, i):
			# print("Q")
			if a[x][1]:
				a[x][0], a[x + 1][0] = a[x + 1][0], a[x][0]
			else:
				flag = False
				break
		if flag != True:
			break
	if flag:
		print("YES")
	else:
		print("NO")

main()
#f()
