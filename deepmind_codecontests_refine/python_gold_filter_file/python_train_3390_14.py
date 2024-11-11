m,n = input().split()
result = "#Black&White"
for i in range(int(m)):
	for j in input().split():
		if j not in ('B','W','G'): result = "#Color"

print(result)