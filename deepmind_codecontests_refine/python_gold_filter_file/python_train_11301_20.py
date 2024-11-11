a,b,c,d,e = map(int,input().split())
t = max(a,c)
t1 = min(b,d)
if t1  >= t:
	if e>=t and e<=t1:
		print(t1-t)
	else:
		print(t1+1-t)
else:
	print(0)