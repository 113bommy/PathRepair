s=input()
a=s[0]
b=int(s[1])
if (a in "ah") and (b in [1,8]):
	print(3)
	exit()
if (a in "ah") or (b in [1,8]):
	print(5)
else:
	print(8)