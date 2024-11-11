n=int(input())
a=[int(i) for i in input().split(" ")]

path=[]

for p in range(len(a)):
	path.append(-1)

b=[]

for i in range(len(a)):
	b.append([-1,-1])

for x in range(len(a)):
	
	mul_two=a[x]*2
	done=0
	if(a[x]%3==0):
		done=1
		div_thr=a[x]//3
	
	for y in range(len(a)):
		if(a[y]==mul_two):
			b[x][0]=y
			break
		elif(done==1):
			if(a[y]==div_thr):
				b[x][1]=y
				break

for i in range(len(a)):
	
	cond=True
	k=i
	count=0
	ans=0
	path_var=0

	for x in range(len(a)):
		path[x]=-1
	path[path_var]=a[i]
	path_var+=1
	while(cond==True):
		if(b[k][0]!=-1):
			k=b[k][0]
			count+=1
			path[path_var]=a[k]
			path_var+=1
			if(count==len(a)-1):
				ans=1
				#temp=a[k]
				break
		elif(b[k][1]!=-1):
			k=b[k][1]
			path[path_var]=a[k]
			path_var+=1
			count+=1
			if(count==len(a)-1):
				ans=1
				#temp=a[k]
				break
		else:
			break
	
	if(ans==1):
		break

#print(temp,end=" ")
#for d in range(len(b)):
#	if(b[d][0]==-1 and b[d][1]==-1):
#		temp=a[d]

#print(temp,end=" ")
for i in range(len(path)):
	print(path[i],end=" ")