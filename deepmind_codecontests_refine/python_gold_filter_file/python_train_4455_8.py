n,k=list(map(int,input().split()))
s=0
for i in range(k,n+2):
	s+=i*(2*n-i+1)//2+1-(i*(i-1))//2
print(s%(1000000007))