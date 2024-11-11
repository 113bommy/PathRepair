def binarysearch(ar,l,r,x):
	if r >= l:
		mid = l + (r-l)//2
		if ar[mid] == x:
			return mid
		elif ar[mid] < x:
			return binarysearch(ar,mid+1,r,x)
		else:
			return binarysearch(ar,l,mid-1,x)	
	return -1			
def funky(n):
	a = (int((2*n)**(.5))+int(2))
	ar = []
	for i in range(1,a):
		k = int(i*(i+1)/2)
		ar.append(k)
	return ar	
def CoolestNum(ar,l,r,x):
	b = binarysearch(ar,l,r,x/2)
	if b != -1:
		return "YES"
	else:		
		g = len(ar)	
		for i in range(g-1,-1,-1):
			if ar[i] > x//2:
				diff = x - ar[i]
				term = binarysearch(ar,0,g-1,diff)
				if term != -1:
					return "YES"
	return "NO"			

n = int(input())
ar = funky(n)
q = len(ar)
print(CoolestNum(ar,0,q-1,n))
