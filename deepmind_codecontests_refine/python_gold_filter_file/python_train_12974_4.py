R =lambda: list(map(int,input().split()))
n,m = R()
l = R()
c,i = m,0
while c>0:
	c-=(86400-l[i])
	i+=1
print(i)