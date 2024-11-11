def gcd(n0, n1):
	r=n1%n0
	if r:
		return gcd(r, n0)
	return n0
a,b,n = map(int, input().split())
s=an=0
while n:
	if s<=an:
		if n>=gcd(min(a,n), max(a,n)):
			n-=gcd(min(a,n), max(a,n))
			s+=1
		else:
			break
	else:
		if n>=gcd(min(b,n), max(b,n)):
			n-=gcd(min(b,n), max(b,n))
			an+=1
		else:
			break
if s>an:
	print(0)
else:
	print(1)