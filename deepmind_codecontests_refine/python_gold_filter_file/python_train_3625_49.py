import re
s = input()
pattern = re.compile(r"^A[a-z]+C[a-z]+$")
match = pattern.match(s)
if(match):
	print ("AC")
else:
	print("WA")
