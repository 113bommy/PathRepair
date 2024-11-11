n, k = [int(i) for i in input().split()]
s = [[int(i), 0] for i in input().split()]
c = [int(i) for i in input().split()]
for i in c:
	s[i-1][1] = 1
a = 0
for i in s:
	a+=i[0]
ans = 0
for i in range(n-1):
	if s[i][1]:
		a-=s[i][0]
		ans += s[i][0]*(a)
	else:
		if not s[i+1][1]:
			ans+=s[i][0]*s[i+1][0]
if s[n-1][1]:
	a-=s[n-1][0]
	ans += s[n-1][0]*(a)
else:
	if not s[0][1]:
		ans+=s[n-1][0]*s[0][0]
print(ans)
