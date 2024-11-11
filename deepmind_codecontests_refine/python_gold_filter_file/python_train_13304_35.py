l, r = map(int, input().split())
if r-l >2019:
	l = r-2019
s = 10**9
for i in range(l,r+1):
	for j in range(i+1,r+1):
		s = min(s,i*j%2019)
print (s)
