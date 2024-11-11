n, love, money = map(int, input().split(' '))
prices = [int(x) for x in input().split(' ')]
loveIndex = love - 1
l = 1
for i in range(len(prices)):
	try:
		leftPossible = prices[loveIndex - l] if (loveIndex - l >= 0) else 0
	except IndexError:
		leftPossible = float('inf')
	try:
		rightPossible = prices[loveIndex + l]
	except IndexError:
		rightPossible = float('inf')

	if leftPossible <= money and leftPossible != 0:
		break
	elif rightPossible <= money and rightPossible != 0:
		break
	else:
		l += 1

print(l * 10)

