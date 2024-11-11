n, p, k = map(int, input().split())


s = '('+ str(p) +')'

for _ in range(1,k+1):
	if p-_ > 0:
		s = str(p-_) + ' ' + s
	if p+_ <= n:
		s = s + ' ' + str(p+_)

if p + k < n:
	s = s+' >>'

if p - (k+2) >= 0:
	s = '<< ' + s

print(s)