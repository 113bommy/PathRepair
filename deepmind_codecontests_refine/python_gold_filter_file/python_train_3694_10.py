a = []

for i in range(97,123):
	a.append(chr(i))

s = input()

n = len(s)

flag = False

for i in range(n+1):
	if(flag == False):
		for j in a:
			x = s[0:i] + j + s[i:n]
			if(x == x[::-1]):
				y = x
				flag = True
				break

if(flag == False):
	print("NA")
else:
	print(y)