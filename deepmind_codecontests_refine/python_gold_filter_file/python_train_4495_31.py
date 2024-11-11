a=input()
a=a.lower()
b=[]
c=['a','e','i','o','u','y']
for i in a:
	if i not in c:
		b.append("."+i)
print(''.join(b))
	