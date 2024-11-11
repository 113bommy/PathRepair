n, k, q = [int (a) for a in input().strip().split()]
t = [int (a) for a in input().strip().split()]

s = []

def ssort():
	for i in range(len(s)-1):
		if s[i] > s[i+1]:
			s[i], s[i+1] = s[i+1], s[i]
	if len(s) > k:
		s.pop(0)
	
for i in range(q):
	type, id = [int (a) for a in input().strip().split()]
	if type == 1:
		if len(s) == 0:
			s = [t[id-1]]
		else:
			if len(s) < k or t[id-1] > s[0]:	
				s = [t[id-1]] + s
				ssort()
	else:
		if t[id-1] in s:
			print("YES")
		else:
			print("NO")