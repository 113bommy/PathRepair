n=int(input())
val=0
for i in range(n):
	s=input()
	if s[0]=='+' or s[0]=='-':
		if s[0]=='+':
			val=val+1
		else:
			val=val-1
	else:
		if s[1]=='+':
			val=val+1
		else:
			val=val-1
print(val)
