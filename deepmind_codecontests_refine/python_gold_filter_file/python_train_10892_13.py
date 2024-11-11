n = int(input())
s = input()
ans = 0

l=0
r=0
u=0
d=0

for i in range(0, n):
	if s[i] == 'L':
		l+=1
	elif s[i] == 'R':
		r+=1
	elif s[i] == 'U':
		u+=1
	else:
		d+=1

ans = 2*min(l, r)
ans += 2*min(u, d)
print(ans)