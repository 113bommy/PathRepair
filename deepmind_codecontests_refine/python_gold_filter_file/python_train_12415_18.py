def mex(ls,v):
	for i in range(v+1):
		if i not in ls:
			return i
t=int(input())
for i in range(t):
		n=int(input())
		li=list(map(int,input().split()))
		k=0
		lf=[]
		while True:
			a=mex(li,n)
			if a==n:
				li.pop()
				li.insert(n-1,n)
			
				k+=1
				lf+=[n]
				continue
		
			elif a<n-1:
				li.pop(a)
				li.insert(a,a)
				k+=1
	
				lf+=[a+1]
				continue
		
				
			for j in range(n):
				if li[j]!=j:
					if j in li:
						c=li.index(j)
						li.pop(c)
						li.insert(c,a)
						k+=1
						lf+=[c+1]
		
						break
					else:
						li.pop(j)
						li.insert(j,a)
						k+=1
		
						lf+=[j+1]
						break
			else:
				break
			if j==n-1:
				break
		print(k)
		lf=list(map(str,lf))
		print(" ".join(lf))
		
			
	
			
		
		
		