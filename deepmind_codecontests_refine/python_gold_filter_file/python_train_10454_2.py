k,x,n,m=map(int,input().split())
 
def calc(k,a,b,op1,ed1,op2,ed2):
	if k==2:
		return b
	return calc(k-1,b,a+b+(ed1&op2),op2,ed2,op1,ed2)
 
def make(len,a,op,ed):
	res,i="",0
	if op:
		res+="C"
		i+=1
	if ed:
		len-=1
	while a:
		res+="AC"
		a-=1
		i+=2
	while i<len:
		res+="P"
		i+=1
	if ed:
		res+="A"
	return res
 
 
def check(a,b,op1,ed1,op2,ed2):
	if (2*a+op1+ed1>n) or (2*b+op2+ed2>m):
		return 0
	if calc(k,a,b,op1,ed1,op2,ed2) == x:
		print(make(n,a,op1,ed1))
		print(make(m,b,op2,ed2))
		return 1
 
flag=0
for i in range(0,(n>>1)+1):
	for j in range(0,(m>>1)+1):
		for l in range(0,16):
			if check(i,j,l&1,(l>>1)&1,(l>>2)&1,(l>>3)&1):
				flag=1
				break
		if flag:
			break
	if flag:
		break
if not flag:
	print("Happy new year!")
 
