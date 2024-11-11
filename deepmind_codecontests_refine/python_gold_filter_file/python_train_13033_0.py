z=1000000007
def primes(n):
	i=2
	k=n
	p=[]
	while(i*i<=k):
		if(k%i==0):
			p.append(i)
			while(k%i==0 and k!=1):
				k=k//i
		i+=1
	if(k>=2):
		p.append(k)
	return p

def modExp(num,k):
	z=1000000007
	if k==0:
		return 1
	
	if k%2==0:
		return (modExp(num,k//2)**2)%z
	
	else:
		return (num*modExp(num,k-1))%z


x,n=map(int,input().split())
p=primes(x)
ans=1
for num in p:
	i=num
	res=0
	while n//i:
		res+=n//i
		i*=num
	ans=(ans*modExp(num,res))%z

print(ans%z)



