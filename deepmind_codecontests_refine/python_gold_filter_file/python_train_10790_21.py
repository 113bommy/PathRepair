s = list(map(int,input().split()))
d = {"a":s[0],"b":s[1],"c":s[2]}
a = max(s[0],s[1])
b = min(s[0],s[1])
t = a - b
if s[2] <= t:
	print(2*b+2*s[2])
elif s[2] > t:
	if (s[2] - t)%2 == 0:
		print(2*b+2*t+s[2]-t)
	else:
		print(2*b+2*t+s[2]-t-1)
