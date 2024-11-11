n,m=map(int,input().split())
arr=[]
for i in range(m):
	x,y=map(int,input().split())
	arr.append((x,y))
dict1={}
for i in range(1,n+1):
	dict1[i]=[]
for i in range(m):
	dict1[arr[i][0]].append(arr[i][1])
for i in range(1,n+1):
	dict1[i].sort()
ansarr=[]
for i in range(1,n+1):
	temp=0
	j=1
	while(j<=n):
		temp=max(temp,len(dict1[j]))
		j+=1
	j=1
	maxdist=0
	fans=0
	tempdist=10**9
	while(j<=n):
		if(len(dict1[j])==temp):
			if(j>=i):
				mindist=10**9
				for l in range(len(dict1[j])):
					if(dict1[j][l]<j):
						mindist=min(mindist,n-i+dict1[j][l])
					else:
						mindist=min(mindist,dict1[j][l]-i)
				if(mindist!=10**9):
					maxdist=max(maxdist,mindist)
			else:
				mindist=10**9
				for l in range(len(dict1[j])):
					if(dict1[j][l]<j):
						mindist=min(mindist,n-i+n+dict1[j][l])
					else:
						mindist=min(mindist,n-i+dict1[j][l])
				if(mindist!=10**9):
					maxdist=max(maxdist,mindist)
			fans=max((temp-1)*n+maxdist,fans)
		elif(len(dict1[j])==temp-1 and temp!=1 and j<i):
			tempdist=10**9
			#dist1=(temp-2)*n
			for l in range(len(dict1[j])):
				if(dict1[j][l]>=i):
					tempdist=min((temp-1)*n+dict1[j][l]-i,tempdist)
					#fans=max(fans,tempdist)
				elif(j<dict1[j][l]<i):
					tempdist=min((temp-1)*n-(i-dict1[j][l]),tempdist)
					#fans=max(fans,tempdist)
				else:
					tempdist=min((temp-1)*n+n-i+dict1[j][l],tempdist)
					#fans=max(fans,tempdist)
			if(tempdist!=10**9):
				fans=max(fans,tempdist)
		elif(len(dict1[j])==temp-1 and temp!=1 and j>=i):
			tempdist=10**9
			for l in range(len(dict1[j])):
				if(j>dict1[j][l]>=i):
					tempdist=min((temp-1)*n+dict1[j][l]-i,tempdist)
					#fans=max(fans,tempdist)
				elif(dict1[j][l]>j):
					tempdist=min((temp-2)*n+dict1[j][l]-i,tempdist)
					#fans=max(fans,tempdist)
				else:
					tempdist=min((temp-2)*n+n-i+dict1[j][l],tempdist)
					#fans=max(fans,tempdist)
			if(tempdist!=10**9):
				fans=max(fans,tempdist)
		j+=1
	ansarr.append(fans)
print(*ansarr)




