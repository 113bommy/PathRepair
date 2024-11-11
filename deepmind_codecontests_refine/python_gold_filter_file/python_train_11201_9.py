t = int(input())
x = []
y = []
flag = 0
for _ in range(t):
	n, m = map(int, input().split())
	if n != m:
		flag = 1
	x.append(n)
	y.append(m)
x.sort(reverse=True)
if flag == 1:
	print("rated")
elif flag == 0 and x == y:
	print("maybe")
else:
	print("unrated")