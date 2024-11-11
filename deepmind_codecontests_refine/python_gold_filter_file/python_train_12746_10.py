ref = ['A','H','I','M','O','T','V','U','W','X','Y']
s = input()
if s == s[::-1]:
	still_okay = True
	for i in s:
		found = False
		for j in ref:
			if i==j:
				found = True
				break
		if(not found):
			still_okay = False
			break
	if(still_okay):
		print("YES")
	else:
		print("NO")
else:
	print('NO')