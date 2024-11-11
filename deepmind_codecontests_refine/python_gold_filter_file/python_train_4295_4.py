import sys
input = sys.stdin.buffer.readline
def I(): return(list(map(int,input().split())))
def sieve(n):
	a=[1]*n
	for i in range(2,n):
	    if a[i]:
	        for j in range(i*i,n,i):
	            a[j]=0
	return a

for __ in range(int(input())):
	h,c,t=I()
	# for n in range(1,22,2):
	# 	if n%2:
	# 		avg=(h+c*(n-1)//2+h*(n-1)//2)/n
	# 	else:
	# 		avg=(h*n//2+c*n//2)/n
	# 	print(avg-(h+c)/2,n)

	if h==t:
		print(1)
		continue
	# if (h+c)/2>=t:
	# 	print(2)
	# 	continue
	# if (h+c)/2>t:
	# 	if (h+c)/2<h:
	# 		print(2)
	# 	else:
	# 		print(1)
	# 	continue
	if (h+c)/2>=t:
		print(2)
		continue
	if t>=(h*2+c)/3:
		x1=(h*2+c)/3
		x2=h
		if abs(x2-t)<=abs(x1-t):
			print(1)
		else:
			print(3)
		continue
	l=1
	r=10**30
	ans=10**100
	# print("---------")
	left=t-(h+c)/2
	# print(left)

	while(l<=r):
		mid=(l+r)//2
		n=mid
		delta=(h-c)/(2*(2*n+1))
		# print(mid)
		# print(delta,2*n+1)
		if delta==left:
			ans=n
			break
		if delta<left:
			ans=n
			r=mid-1
		else:
			l=mid+1
	n=ans
	delta1=(h-c)/(2*(2*n+1))
	delta2=(h-c)/(2*(2*n-1))
	# print(delta1)
	if abs(delta1-left)<abs(delta2-left):
		print(2*n+1)
	else:
		print(2*n-1)

	# print(2*ans+1)
	# print("---------")


	



