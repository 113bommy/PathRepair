def gcd(a,b):
	if b==0:
		return a
	return gcd(b,a%b)
t,w,b=list(map(int,input().split()))
if w==b:
	print(1,'/',1,sep='')
	exit(0)
a=min(w,b)-1
if a>t:
	print('1/1')
	exit(0)
q=(w*b)//gcd(w,b)
k=t//q
if k:
	ans=k+a+(k-1)*a
	ans+=min(t%q,a)
else:
	ans=a
m=gcd(ans,t)
ans=ans//m
t=t//m
print(ans,'/',t,sep='')