#http://codeforces.com/problemset/problem/686/A
inp = list(map(int,input().split()))
tCases = inp[0]
iceCream = inp[1]
store = []
distress = 0

for x in range(tCases):
	temp = list(input().split())
	store.append(temp)

for x in store:
	if x[0] == "-":
		if int(x[1]) <=iceCream:
			iceCream -= int(x[1])
		else:
			distress += 1
	else:
		iceCream += int(x[1])

print(str(iceCream) + " " + str(distress))
