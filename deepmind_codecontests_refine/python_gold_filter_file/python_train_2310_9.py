str1=input()
l1=[]

l1.append(str1[0])

for i in range(1,len(str1)):
	if str1[i]>=l1[i-1]:
		l1.append(l1[i-1])
	else:
		l1.append(str1[i])
#print(l1)
for i in range(len(str1)):
	if(str1[i]==l1[i]):
		print("Mike")
	else:
		print("Ann")

