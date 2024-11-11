a,b=map(int,input().split())
num=0
while a//b>=1:
	a-=b
	a+=1
	num+=b
print(num+a)