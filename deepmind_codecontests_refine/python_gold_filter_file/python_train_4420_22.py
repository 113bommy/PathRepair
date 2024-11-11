s=input()
ns=s[1:len(s)-1]
se=set()
for i in ns:
	if i!="," and i!=" ":
		se.add(i)
print(len(se))