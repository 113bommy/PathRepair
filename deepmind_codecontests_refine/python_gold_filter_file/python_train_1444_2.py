n=int(input())
s=int(input())

def f(b,n):
	if b < 2:
		return 0
	if n < b:
		return n
	else:
		return f(b,n//b)+n%b

ans=-1
if s==n:
	ans=n+1
else:
	for _b in range(2,int(n**0.5)+1):
		if f(_b,n)==s:
			ans=_b
			break
	if ans==-1:
		for _p in range(int(n**0.5),0,-1):
			_b = (n-s)//_p+1
			if f(_b,n)==s:
				ans=_b
				break
print(ans)