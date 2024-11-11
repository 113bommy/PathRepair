def powe(a,b,mod):
	res = 1
	a = a%mod
	while b>0:
		if(b&1==1):
			res = (res*a)%mod
		b=b>>1
		a = (a*a)%mod
	return res
h,w = map(int,input().split())
ri = list(map(int,input().split()))
ci = list(map(int,input().split()))
const = [[0 for _ in range(w)] for _ in range(h)]
flag=True
for i in range(h):
	for j in range(ri[i]+1):
		if j<ri[i]:
			const[i][j]=1
		else:
			if j<w:
				const[i][j]=-1
for i in range(w):
	for j in range(ci[i]+1):
		if j<ci[i]:
			if const[j][i]!=-1:
				const[j][i]=1
			else:
				flag=False
				break
		else:
			if j<h:
				if const[j][i]==1:
					flag=False
					break
				const[j][i]=-1
	if flag==False:
		break
count_0 = 0
if flag==False:
	print(0)
else:
	for i in range(1,h):
		for j in range(1,w):
			if const[i][j]==0:
				count_0+=1
	print(powe(2,count_0,1000000007))

