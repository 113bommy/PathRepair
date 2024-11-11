t=int(input())
a=[]
b=[]
for i in range(t):
	p=int(input())
	h=list(map(int,input().split()))
	a.append(p)
	b.append(h)

def tully(a,b):
	flag=1
	p=-1
	for i in range(2,a):
		if b[0]+b[1]<=b[i]:
			flag=0
			p=i
			break
	return p
for i in range(t):
	y=tully(a[i],b[i])
	if y==-1:
		print("-1")
	else:
		print(f"1 2 {y+1}")
