total = int(input())
c1 = 0
c2 = 0
c3 = 0
for i in input().split():
	if i == '1':
		c1 += 1
	elif i == '2':
		c2 += 1
	elif i == '3':
		c3 += 1

print(total - max(max(c1,c2),c3))