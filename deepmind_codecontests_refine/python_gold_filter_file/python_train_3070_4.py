a=input()
b=input()
c1,c2,ans,v=0,0,0,[]
for i,j in zip(a,b):
	if i!=j:
		ans+=1
		if c1<c2:
			v.append(i)
			c1+=1
		else:
			v.append(j)
			c2+=1
	else:
		v.append(i)
if ans&1:
	print('impossible')
else:
	print(''.join(v))



