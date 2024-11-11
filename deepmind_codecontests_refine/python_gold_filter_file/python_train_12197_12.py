n= int(input())
vovel=["a",'e','i','o','u']*2000
def perfect(n):
	for j in range(5,n+1):
		if(n%j==0):
			if(n//j>4):
				return sorted([j,n//j])
	else:
		return 1
if(n<25 or perfect(n)==1):
	print(-1)
else:
	r,c=perfect(n)
	vovel=vovel[:r]
	for i in range(c):
		print(*vovel,sep="",end="")
		vovel=vovel[1:]+[vovel[0]]


