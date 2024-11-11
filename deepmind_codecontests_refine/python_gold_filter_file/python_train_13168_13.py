b = {}
s = {}
n, k = map(int,input().split())
for i in range(n):
	d, p, q = map(str,input().split())
	p = int(p)
	q = int(q)
	if d == 'B':
		b.setdefault(p)
		if b[p] == None:
			b[p] = q
		else:
			b[p] += q
	else:
		s.setdefault(p)
		if s[p] == None:
			s[p] = q
		else:
			s[p] += q
##print(b, s)
s1 = s.keys()
s1 = list(s1)
s1.sort()
b1 = b.keys()
b1 = list(b1)
b1.sort(reverse = True)
s1 = s1[:k]
s1.sort(reverse = True)
for i in range(min(k, len(s1))):
	print("S", s1[i], s[s1[i]])

for i in range(min(k, len(b1))):
	print("B", b1[i], b[b1[i]])