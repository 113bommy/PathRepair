n,m=[int(x) for x in input().split(' ')]
a=[]
ranges=[]
for i in range(n):
	s=input()
	row=[]
	for x in s:
		if(x=='#'):
			row.append(-1)
		elif(x=='.'):
			row.append(0)
		else:
			print('TNP')
	a.append(row)

does_one=False
does_two=False
khalis=[-1]

def is_fine_horizontal(I):
	global a
	global ranges
	global does_one
	global does_two
	p1=0
	while(a[I][p1]==0):
		p1+=1
		if(p1==m):
			break
	p2=(m-1)
	while(a[I][p2]==0):
		p2-=1
		if(p2==-1):
			break
	ranges.append([p1,p2])
	if(p2<p1):
		does_one=True
		khalis.append(I)
		return(True)
	for i in range(p1,p2+1):
		if(a[I][i]==0):
			return(False)
 
	return(True)
 
def is_fine_vertical(I):
	global a
	global does_two
	p1=0
	while(a[p1][I]==0):
		p1+=1
		if(p1==n):
			break
	p2=(n-1)
	while(a[p2][I]==0):
		p2-=1
		if(p2==-1):
			break
	if(p2<p1):
		does_two=True
		return(True)
	
	for i in range(p1,p2+1):
		if(a[i][I]==0):
			return(False)
 
	return(True)
 
bhul=True
for i in range(n):
	if(not is_fine_horizontal(i)):
		bhul=False
		break
if(bhul):
	for i in range(m):
		if(not is_fine_vertical(i)):
			bhul=False
			break
 
def is_common(l1,r1,l2,r2):
	if(r1<l2):
		return(False)
	elif(r2<l1):
		return(False)
	return(True)
khalis.append(n)

# if(n==9 and m==1000):
# 	print(ranges)
# 	print(khalis)

if(bhul):
	if(does_one^does_two):
		print(-1)
	elif(does_one and does_two):
		if(len(khalis)==(n+2)):
			print(0)
		else:
			q=0
			for k in range(1,len(khalis)):
				if((khalis[k]-khalis[k-1])==0):
					q+=0
				elif((khalis[k]-khalis[k-1])==1):
					q+=0
				else:
					t1=khalis[k-1]+1
					t2=khalis[k]
					if(t2-t1==1):
						q+=1
					else:
						ans=1
						for i in range(t1+1,t2):
							if(not is_common(ranges[i][0],ranges[i][1],ranges[i-1][0],ranges[i-1][1])):
								ans+=1
						q+=ans
			print(q)
	else:
		if(n==1):
			print(1)
		else:
			ans=1
			for i in range(1,n):
				if(not is_common(ranges[i][0],ranges[i][1],ranges[i-1][0],ranges[i-1][1])):
					ans+=1
			print(ans)
else:
	print(-1)