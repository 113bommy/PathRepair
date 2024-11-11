a = list(map(int, input().split()))
legs = False
leg = 0
for i in range(len(a)):
	if a.count(a[i]) >= 4:
		legs = True
		leg = a[i]
		break
if legs == False:
	print ("Alien")
	exit()
for i in range(len(a)):
	if a[i] == leg:
		a[i] = 0
a.sort()
#print (a)
if a[len(a)-1] == a[len(a)-2]:
	print ("Elephant")
else:
	print ("Bear")
	

 