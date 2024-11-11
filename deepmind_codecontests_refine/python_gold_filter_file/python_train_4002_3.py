password=input()
s_char=0;c_char=0;digit=0
n=len(password)
if n>=5:
	for i in password:
		if i.islower():
			s_char+=1
		elif i.isupper():
			c_char+=1
		elif i.isdigit():
			digit+=1

	if s_char and c_char and digit:
		print("Correct")
	else:
		print("Too weak")
else:
	print("Too weak")