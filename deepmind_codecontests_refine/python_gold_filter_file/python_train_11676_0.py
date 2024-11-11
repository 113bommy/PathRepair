# inputCopy
# 1098
# outputCopy
# 20
# inputCopy
# 10
# outputCopy
# 19

def f(n):
	n+=1
	while(n%10==0):
		n/=10
	return int(n)

n=int(input())
c=1
s=0
if(n>=1 and n<=9):
	print(9)
else:
	while(n!=1):
		n=f(n)
		if(n<10):
			break
		else:
			c+=1
	print(c+9)