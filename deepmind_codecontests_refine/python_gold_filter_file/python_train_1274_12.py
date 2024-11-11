
itr=int(input())

def m_sum(l,arr):
	s=0
	if arr[0]>0:
		c='P'
		max_i=0
	else:
		c='N'
		max_i=-(10**9)
	l=len(arr)
		
	for i in range(len(arr)):
		val=arr[i]
	
		if c=='P':
			if  val>max_i:
				max_i=val
			
			if i<=l-2 and arr[i+1]<0:
				s+=max_i
				max_i=-(10**9)
				c='N'
			elif i==l-1:
				s+=max_i
				
		elif c=='N':
			if val>max_i:
				max_i=val
			
			if i<= l-2 and arr[i+1]>0:
				s+=max_i
				max_i=0
				c='P'
			elif i==l-1:
				s+=max_i
	return s


for _ in range(itr):
	l=int(input())
	arr=list(map(int,input().split()))
	ans=m_sum(l,arr)
	print(ans)
