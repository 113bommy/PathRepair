d,k,a,b,t=tuple(map(int,input().split()))
if(d>k):
	dist=d-k
	s=k*a
	if(t+k*a) <= k*b:
		s=s+(dist//k)*(t+k*a)
		dist=dist%k
	else:
		s=s+dist*b
		dist=0
	if t+dist*a > dist*b:
		s=s+dist*b
	else:
		s=s+t+dist*a
	print(s)
else:
	print(d*a)