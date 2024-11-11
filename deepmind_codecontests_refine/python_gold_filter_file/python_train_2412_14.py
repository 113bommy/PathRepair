from math import ceil
r = int(input())
x,y = 1,1
while y>0:
	y = (r-x*x-x-1)/(2*x)
	if float(y)==ceil(y):break
	x+=1
print(x,int(y)) if float(y)==ceil(y) and y>0 else print('NO')