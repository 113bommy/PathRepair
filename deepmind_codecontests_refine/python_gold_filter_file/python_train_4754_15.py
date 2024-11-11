from pprint import pprint
a = list(map(int,input().split()))
mask  = [[a[i]//14 + (1 if (((j-i)%14)<=(a[i]%14) and a[i]>0 and j!=i) else 0) for j in range(14)] for i in range(14)]

def s(w):
	r = 0
	for i in range(14):
		if(w!=i):
			l = a[i] + mask[w][i]
		else:
			l = mask[w][i]
		if(l%2 == 0):
			r += l
	return r
res = 0
for w in range(14):
	if(a[w]):
		res = max(res,s(w))

print(res)