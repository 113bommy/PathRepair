n=int(input())
l=1
for i in range(1,int(n**0.5)+1):
	if n%i==0:
		l=i
k=n//l
print(l+k-2)