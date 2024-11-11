n = int(input())
a = [int(i) for i in input().split()]
a.sort()
count = 0
c1 = 0
c2 = 0
for i in range(n):
	if(a[i] == a[2]):
		count+=1
		if(i==0):
			c1 = 1
		if(i==1):
			c2 = 1
if(c1 == 1):
	print((count)*(count-1)*(count-2)//(3*2))
elif(c2==1):
	print((count)*(count-1)//(2))
else:
	print(count)