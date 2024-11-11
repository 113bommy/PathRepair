n,k,*a,=map(int,open(0).read().split())
def f(li):
	b=[0]*(n+1)
	for i,x in enumerate(li):
		b[max(0,i-x)]+=1
		b[min(i+x+1,n)]-=1
	for i in range(n):
		b[i+1]+=b[i]
	return b[:-1]
for _ in range(k):
	a=f(a)
	if a==[n]*n:
		print(*a)
		exit()
print(*a)