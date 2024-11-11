def ms(c):
	"""months"""
	if c>1:
		return 31-(c-2)%5%2
	else:
		return 31-3*c

def fy():
	"""get four years"""
	for c in range(6*12):
		yield str(ms(c%12))

def fys():
	"""get four years str"""
	v=list(fy())
	v[12*3+1]='29'
	return ''.join(v)

input()
v=[c for c in input().split()]
t=''.join(v)
fs=fys()
s='YES' if t in fs else 'NO'
print(s)