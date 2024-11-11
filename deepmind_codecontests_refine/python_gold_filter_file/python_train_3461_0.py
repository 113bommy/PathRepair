n,k = map(int,input().split())
p = 998244353
def pot(a,d):
	res = 1
	mno = a
	while d > 0:
		if d%2 == 1:
			res = (res*mno)%p
		mno = (mno*mno)%p
		d//=2
	return res
silnia = [1] * (n+1)
for i in range(2,n+1):
	silnia[i] = (i*silnia[i-1])%p
#dla a_1 = i ile mozliwych (k-1)-tek liczb od 2 do n//a_i
wyn = 0
for a1 in range(1,n+1):
	if n//a1 < k:
		break
	else:
		zb = (n//a1)-1
		#wyn += zb po k-1
		wyn += silnia[zb] * pot(silnia[zb-k+1], p-2) * pot(silnia[k-1], p-2)
print(wyn%p)