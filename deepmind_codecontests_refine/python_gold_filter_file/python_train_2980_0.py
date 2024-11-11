k, a, b = map(int, input().split())
A = []
for _ in range(3):
	temp = [int(x) for x in input().split()]
	A.append(temp)
B = []
for _ in range(3):
	temp = [int(x) for x in input().split()]
	B.append(temp)
flag, ac, bc, cur = 0, 0, 0, 1
m = {}
ans1, ans2 = [0]*1000, [0]*1000
while cur <= k:
	if (a, b) in m and flag != 1:
		add1 = ans1[cur-1] - ans1[m[(a, b)]-1]
		add2 = ans2[cur-1] - ans2[m[(a, b)]-1]
		l = cur-m[(a, b)]
		times = (k-(cur-1))//l
		ac += add1*times
		bc += add2*times
		cur += l*((k-(cur-1))//l)
		cur -= 1
		# x, y = a-1, b-1
		# a, b = A[x][y], B[x][y]
		flag = 1
	else:
		m[(a, b)] = cur
		if cur <= 500:
			ans1[cur], ans2[cur] = ans1[cur-1], ans2[cur-1]
		if a == b%3 + 1:
			ac += 1
			if cur <= 500:
				ans1[cur] += 1
		if b == a%3 + 1:
			bc += 1
			if cur <= 500:
				ans2[cur] += 1
		x, y = a-1, b-1
		a, b = A[x][y], B[x][y]
	cur += 1
print(ac, bc)
