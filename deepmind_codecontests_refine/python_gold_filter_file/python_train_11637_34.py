import collections

N=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))

Atmp = 0
Btmp = 0

INF=10e18


C=collections.Counter(A)
D=collections.Counter(B)

currentC = 0
currentD = 0

rotation = 0



for n in range(N+1):

	if N < C[n] + D[n]:
		rotation = INF
		break

	currentC += C[n]
	rotation = max( rotation, currentC - currentD )
	currentD += D[n]

if rotation == INF:
	print("No")
else:
	print("Yes")
	
	print(" ".join(map(str,B[-rotation:] + B[:-rotation])))




