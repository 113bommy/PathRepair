N,K = map(int,input().split())
A = list(map(int,input().split()))
A.sort()
need = []
iranaiko = []
for a in A:
	if a >= K:
		need.append(a)
	elif a in need:
		need.append(a) 
	elif a in iranaiko:
		pass
	else:
		z = 0
		B = A[:]
		B.remove(a)
		fusoku = [K - i - 1 for i in range(a)]
		for bi,b in enumerate(B):
			if b >= K:
				bi = bi - 1
				break
		B = B[:bi + 1]
		B.reverse()
		C = [0]
		for b in B:
			D = []
			for c in C:
				if b + c < K:
					if b + c in fusoku:
						z = 1
						need.append(a)
						break
					D.append(b + c)
				
			D.append(0)
			C = D[:]
			if z == 1:
				break
			
		if z == 0:
			iranaiko.append(a)

print(N - len(need))
