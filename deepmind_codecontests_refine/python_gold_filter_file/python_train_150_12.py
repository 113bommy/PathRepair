bl='*'

def fi(s,n):
	"""get fields index"""
	for c in range(n):
		if s[c]==bl:
			yield c

def ig(s,n):
	"""is good"""
	fs=list(fi(s,n))
	if len(fs)==0:
		return 0
	for c in range(1,(n-fs[0])//4+1):
		for d in fs:
			if s[d:d+5*c:c]==5*bl:
				#print(d,c)
				return 1
	return 0

n=int(input())
s=input()
s='yes' if ig(s,n) else 'no'
print(s)