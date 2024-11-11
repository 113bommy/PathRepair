n,m,L,R = map(int,input().split())
p = 998244353*2
pp = p//2
#liczba pokryc n x m ze jest parzyscie wiele zer albo parzyscie wiele jedynek
def pow(a,w):
	wyn = 1
	mn = a
	while w > 0:
		if w%2 == 1:
			wyn = (wyn * mn)%p
		mn = (mn*mn)%p
		w //= 2
	return wyn
dupsko = pow((R-L+1), m*n)
if L == R:
	print(1)  
else:
	if (m*n)%2 == 1:
		print(dupsko%pp)
	else:
		print((dupsko - dupsko//2)%pp)
		