# your code goes here

a,b = map(int, input().split())
c = 1
if b-a>=10:
	print("0")
else:
	for i in range(a+1, b+1):
		c=c*i
	print(c%10)