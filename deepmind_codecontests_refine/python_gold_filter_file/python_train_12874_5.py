n=int(input())
a=sorted(list(map(int, input().split())))
count=0;d=None
for i in range(n):
	if d is None:
		if a[i]!=0:
			d=a[i]*-1
			p=d;a[i]=0
			count+=1
	else:
		if a[i]!=0:
			a[i]+=p #To increment/decrease with the previous values
			if a[i]!=0:
				d=a[i]*(-1)
				p+=d 
				count+=1

"""This code example:
	[-1,0,3,4]--->(p=d=1)[0,0,2,3]--->(p=-1,d=-2)[0,0,0,5]--->(p=-6,d=-5)[0,0,0,0]
"""
print(count)