n = int(input())

answ = 0

for i in range(n):
	a = input()
	if "+" in a:
		answ += 1
	else:
		answ -= 1

print(answ)
