x,y,m,n= map(int,input().strip().split())
a=x*m
if x%y==0:
	b=(x//y)*n
	c=x*m
else:
	b=(x//y+1)*n
	c=x//y*n+(x%y*m)
menor=a
if b<menor:
	menor=b
if c<menor:
	menor=c
print(menor)