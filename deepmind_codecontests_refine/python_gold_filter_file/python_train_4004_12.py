import math
def func(n):
	sum=0
	while(n>0):
		sum+=n%10
		n=n//10
	return sum
a,b,c=map(int,input().split())
li=[]
for i in range(1,82):
	num=b*pow(i,a)+c
	if num>=pow(10,9):
		break
	if func(num)==i:
		li.append(num)
print(len(li))
for i in li:
	print(i,end=" ")