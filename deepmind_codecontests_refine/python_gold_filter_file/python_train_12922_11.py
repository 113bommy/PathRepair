n = int(input())
massif = [int(a) for a in input().split()]

fmin = float('inf')
smin = float('inf')
fmax = float('-inf')
smax = float('-inf')

for element in massif:
	if element < fmin:
		if smin > fmin:
			smin = fmin
		fmin = element
	elif element < smin:
		if fmin > smin:
			fmin = smin
		smin = element

	if element > fmax:
		if smax < fmax:
			smax = fmax
		fmax = element
	elif  element > smax:
		if fmax < smax:
			fmax = smax
		smax = element


print(min(smax-fmin,fmax-smin))