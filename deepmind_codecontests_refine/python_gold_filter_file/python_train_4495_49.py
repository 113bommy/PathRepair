s=input().lower()
v=['a','e','i','o','u','y']
z=['.'+x for x in s if x not in v]
for x in z:
	print(x,end='')
	