n=int(input())
s=input()

su=0
a=[]

for x in s:
	if x=='(':
		su+=1
		a.append(su)
	else:
		su-=1
		a.append(su)

cc=0
c=0

if a[n-1]!=0:
	print(-1)
else:
	for x in range(n):
		if a[x]==0 and c!=0:
			c+=1
			cc+=c
			c=0
		elif a[x]<0:
			c+=1
	print(cc)


