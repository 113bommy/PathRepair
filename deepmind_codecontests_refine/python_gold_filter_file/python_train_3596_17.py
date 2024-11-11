
l = list(map(int, input().split()))
stock = l[1]
dis = 0
for i in range(l[0]):
	n = list(map(str, input().split()))
	if n[0] == '+':
		stock += int(n[1])
	else:
		if stock >= int(n[1]):
			stock -= int(n[1])
		else:
			dis += 1
print(stock, dis)
