c,v0,v1,a,l = map(int,input().strip().split(' '))

tp = c - min(v0,v1)
ans = 1

if tp <= 0:
	ans = 1
else:
	i = 1
	while tp > 0:
		cp = v0 + i*a
		cp = min(v1,cp)
		tp = tp - cp + l
		ans+= 1
		i+= 1
print(ans)