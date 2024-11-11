def int_map():
	return map(int, input().split(' '))

n, m = int_map()
res = 0
ml = -1
mr = -1
mu = -1
md = -1
canv = []
for i in range(n):
	b = input()
	canv.append(b)
	# print(b)
	for x, j in enumerate(b):
		if j == 'B':
			# left
			if ml != -1:
				ml = min(x, ml)
			else:
				ml = x
			# right
			if mr != -1:
				mr = max(x, mr)
			else:
				mr = x
			# up
			if mu != -1:
				mu = min(i, mu)
			else:
				mu = i
			# down
			if md != -1:
				md = max(i, md)
			else:
				md = i
ed = max(mr - ml + 1, md - mu + 1)

# if ml > 0 and mr - ed + 1 >= 0:
# 	ml = mr - ed + 1
# elif mr < n and ml + ed - 1 < n:
# 	mr = ml + ed - 1
# else:
# 	print(-1)
# 	exit()
#
# if mu > 0 and md - ed + 1 >= 0:
# 	mu = md - ed + 1
# elif md < n and ml + md - 1 < n:
# 	md = ml + ed - 1
# else:
# 	print(-1)
# 	exit()
if ml == -1:
	print(1)
	exit()

while ml > 0 and mr - ml + 1 < ed:
	ml -= 1
while mr < m-1 and mr - ml + 1 < ed:
	mr += 1

while mu > 0 and md - mu + 1 < ed:
	mu -= 1

while md < n-1 and md - mu + 1 < ed:
	md += 1

if mr - ml + 1 != ed or md - mu + 1 != ed:
	print(-1)
	exit()

for i in range(mu, md+1):
	res += canv[i].count('W', ml, mr+1)

# print(ml, mr, mu, md)
print(res)