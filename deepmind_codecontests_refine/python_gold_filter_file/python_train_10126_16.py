def check(l,mid,D):
	l.sort()
	curr=l[0]+mid
	for i in range(1,len(l)):
		if(curr>l[i]+D):
			# print(i)
			return 0
		elif(curr<l[i]):
			curr=l[i]+mid
		else:
			curr+=mid
	return 1
def binarysearch(l,start,end,d):
	mid=(start+end)/2
	# print(mid,check(l,mid,d) )
	if(end-start<0.000001):
	    return mid
	elif(check(l,mid,d)):
		return max(mid,binarysearch(l,mid+10**(-6),end,d))
	else:
		return binarysearch(l,start,mid-10**(-6),d)
	
for _ in range(int(input())):
	n=int(input())
	d={}
	for i in range(n):
		s=input()
		for j in s:
			if(j in d):
				d[j]+=1
			else:
				d[j]=1
	f=0
	for i in d:
		if(d[i]%n!=0):
			f=1
			break
	if(f):
		print("NO")
	else:
		print("YES")