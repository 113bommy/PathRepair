c,v0,v1,a,l = [int(i)for i in input().split()]
ans = 1
cur = v0
while v0 < c:
	ans+=1
	cur += a
	v0 += min(v1 ,cur ) - l
print(ans)


