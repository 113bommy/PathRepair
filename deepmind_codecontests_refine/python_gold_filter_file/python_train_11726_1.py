I=lambda:list(map(int,input().split()))
n,=I()
l=I()
ans="perfect"
f=0
temp=-1
node=1
for i in range(n):
	if min(l[i],l[i+1])>1:
		ans="ambiguous"
		temp=i+1 
		f=1
		break
if not f:
	print(ans)
else:
	a='0'
	b='0'
	for i in range(1,n+1):
		a+=(" "+str(node))*l[i]
		if i!=temp:
			b+=(" "+str(node))*l[i]
		else:
			b+=(" "+str(node-1))+((" "+str(node))*(l[i]-1))
		node+=l[i]
	print(ans)
	print(a)
	print(b)



