import sys
# from prg import *
from math import *
from copy import copy


n, m = input().split()
n = int(n)
m = int(m)

dat = [int(i) for i in input().split()]

otr = []

for i in range(m):
    l, r = input().split()
    l = int(l)
    r = int(r)
    otr.append((l-1,r-1))

best = 0
otrBest = []
for i in range(n):
	iDat = copy(dat)
	iBest = 0
	iOtrBest = []
	kosInd = 0
	for ii in otr:
		if(ii[0] <= i and i <= ii[1]):
			kosInd += 1
			continue
		else:
			iOtrBest.append(kosInd)
			for iii in range(ii[0],ii[1]+1):
				iDat[iii] -= 1
		kosInd += 1
	iBest = max(iDat) - min(iDat)
	if(iBest > best):
		otrBest = iOtrBest
		best = iBest
		# print(iDat)


print(best)
print(len(otrBest))

for l in otrBest:
	print(l+1, end = ' ')

