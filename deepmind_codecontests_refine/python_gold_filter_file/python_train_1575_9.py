n, m, k=map(int,input().split())

if k==0:
	print(m)

elif m==1:
	print(0)



else:
	total1=m*pow(m-1,k)%998244353
	total2=1
	for i in range(1,k+1):
		total2=total2*(n-i)
	for i in range(1,k+1):
		total2=total2//i

	t=total1*total2%998244353

	print(t)
