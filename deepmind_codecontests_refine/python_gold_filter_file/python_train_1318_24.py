s=input()
a=s.count("-")
b=s.count("o")
if b==0 or a%b==0:
	print("YES")
else:
	print("NO")