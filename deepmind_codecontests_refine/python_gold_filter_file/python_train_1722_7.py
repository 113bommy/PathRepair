def I(): return(list(map(int,input().split())))

n,k=I()
a=I()
b=I()
l=0
# l=104
r=2*(10**9)+1
# r=106
# sumi=sum(a)
# summ=sum(b)
# print(sumi,summ)
while(l<r-1):
	# print(l,r)
	m=(l+r)//2
	s=0
	for i in range(n):
		s+=max(m*a[i]-b[i],0)
	# print(s)
	if s>k:
		r=m
	else:
		l=m
print(l)




