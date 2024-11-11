n = input()

for i in n:
	if i == "0":
		n = n.replace("0","",1)
	else:
		break
if n.count("0")>=6 and n.count("1")>=1:
	print("YES")
else:
	print("NO")
