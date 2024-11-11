n=int(input())
a=[]
s=0
for i in range(n):
	b=list(map(int,input().split()))
	a.append(b)
s+=sum(a[int((n-1)/2)])
for i in range(n):
	s+=a[i][int((n-1)/2)]
	s+=a[i][i]
	s+=a[(n-1)-i][i]
k=int((n-1)/2)	
print(s-3*(a[k][k]))