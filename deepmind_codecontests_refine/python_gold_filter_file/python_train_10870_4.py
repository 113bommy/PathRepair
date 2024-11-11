a=input().split()
l=len(a[1])
p=int(a[1])
d=10**l
m=int(a[2])
w=int(a[0])
c=0
while l*m<=w:
	r=min(int(w/(l*m)),d-p)
	c+=r
	w-=r*l*m
	p=d
	d*=10
	l+=1
print(c)
	 			    	 		 	       		 	 	