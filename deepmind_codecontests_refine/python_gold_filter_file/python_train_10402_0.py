a = int(input())
global s
s = 0

def de(ppp,h):
	re = False
	co  = 0
	global s
	for lo in ppp:
		for j ,cell in enumerate(lo):
			k = j
			p = j
			if k <= 2:
				while cell == lo[k+1] and cell != None:
					co += 1
					if k == 3:
						j = k+1
						break
					k += 1
					j = k
				if co >= 2:
					re = True
					s += (co+1)*cell
					for l in range(5):
						if l >= p and l <= j:
							lo[l] = None
				co = 0

	return re



def mo(ppp,h):
	for i ,roe in enumerate(ppp):
		for j , cell in enumerate(roe):
			kkk = i
			while i != 0 and ppp[kkk-1][j] == None:
				ppp[kkk-1][j] = ppp[kkk][j]
				ppp[kkk][j] = None
				if kkk == 1:
					break
				kkk -= 1


while a != 0:
	ppp = [list(map(int,input().split())) for i in range(a)]
	ppp.reverse()
	while(de(ppp,a) == True):
		mo(ppp,a)
	print(s)

	s = 0

	a = int(input())

