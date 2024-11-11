# import sys
# sys.stdin = open("test.in","r")
# sys.stdout = open("test.out","w")
x,y,z,t1,t2,t3=map(int,input().split())
a=abs(x-y)
b=abs(x-z)
if a*t1>=(a+b)*t2+3*t3:
	print('YES')
else:
	print('NO')