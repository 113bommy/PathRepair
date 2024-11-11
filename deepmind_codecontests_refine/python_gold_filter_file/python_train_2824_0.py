n,k = map(int,input().split())
s = [int(i) for i in input().split()]
s.append(0)
cnt = 1
c = 1
d = []
l,r = 0,1
while r<n:
	if s[l]!=s[r]:
		cnt+=1
		l+=1
		r+=1
	else:
		c = max(c,cnt)
		l=r
		r+=1
		cnt=1

print(max(c,cnt))