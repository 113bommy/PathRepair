def f(s,y):
	if(s in y):
		i=y.index(s)
		for j in range(0,i):
			if(y[j]!="1"):
				return False
		for j in range(i+len(s),len(y)):
			if(y[j]!="1"):
				return False
		return True
	return False
x,y=map(int,input().split())
x=bin(x)[2:]
y=bin(y)[2:]
i=0
j=x.rfind("1")
s=x[i:j+1]
s1=s[::-1]
s3=x+"1"
s4=s3[::-1]
# print(x)
# print(y)
# print(s,s1,s3,s4)
if(x==y or f(s,y) or f(s1,y) or f(s3,y) or f(s4,y)):
	print("YES")
else:
	print("NO")