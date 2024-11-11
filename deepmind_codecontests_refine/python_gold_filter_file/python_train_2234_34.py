s=[int(n) for n in input().split()]
if s[0]>=s[1]:
	j=s[0]//2+(s[0]%2)
	if j%s[1]==0:
		print(j)
	else:
		k=(j//s[1]+1)*s[1]
		print(k)
else:
	print(-1)
	