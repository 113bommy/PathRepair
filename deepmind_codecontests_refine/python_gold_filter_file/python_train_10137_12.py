n= int(input())
string = str(input())
llist = []
i = 0
if n%2 == 0:
	for i in range(n):
		if i and (i%2)==0:
			llist.append('-')
		llist.append(string[i])
else:
	for i in range(n-3):
		if i and (i%2)==0:
			llist.append('-')
		llist.append(string[i])
	if i:
		llist.append('-')
	llist.append(string[n-3])
	llist.append(string[n-2])
	llist.append(string[n-1])
print(''.join(llist))