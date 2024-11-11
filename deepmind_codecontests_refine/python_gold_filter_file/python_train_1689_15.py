

def hashing(p,h):
	for i in range(len(h)):
		ini = i
		fin = i + len(p)

		if fin <= (len(h)):
			check = h[ini:fin]
			p = sorted(p)
			check = sorted(check)
			if p == check:
				return "YES"
	
	return "NO"
q = eval(input())
pro = []
for i in range(q):
	p = input()
	h = input()
	pro.append(hashing(p,h))
for i in pro:
	print(i)
