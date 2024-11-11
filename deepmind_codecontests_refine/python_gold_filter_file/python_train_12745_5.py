import copy
n, p, k = map(int, input().split())
a = []
p1 = copy.copy(p)
a.append('(' + str(p) + ')')
v = 0
while p < n and v < k:
	p += 1
	v += 1
	a.insert(v, str(p))
while k > 0 and p1 > 1:
	p1 -= 1
	a.insert(0, str(p1))
	k -= 1
if '1' not in a and '(1)' not in a:
	a.insert(0, '<<')
if str(n) not in a and '(' + str(n) + ')' not in a:
	a.insert(len(a), '>>')
print(" ".join(a))
