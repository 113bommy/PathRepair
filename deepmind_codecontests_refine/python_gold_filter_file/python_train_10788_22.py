c=0
d=0
n=int(input())
for i in range (n):
	a=input()
	a=a.split()
	if int(a[0])<0:
		c+=1
	elif int(a[0])>0:
		d+=1
if c>=2 and d>=2:
	print ("NO")
else:
	print("YES")
