n, k = input().split()
candies = list(input().split())

# Initialise aryas total candies
arya = 0
bran = 0
flag = -1
for i, x in enumerate(candies):
	arya += int(x)
	if arya > 8:
		arya -= 8
		bran += 8
	else:
		bran += arya
		arya = 0

	# condition for victory
	if bran >= int(k):
		flag = i+1
		break


print(flag)
