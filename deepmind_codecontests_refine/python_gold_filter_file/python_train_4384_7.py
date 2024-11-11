s=0
a,b,k=map(int,input().split())
for x in range(1,k+1):
	w=a-4*(x-1)
	h=b-4*(x-1)
	s+=2*w+2*(h-2)
print(s)
