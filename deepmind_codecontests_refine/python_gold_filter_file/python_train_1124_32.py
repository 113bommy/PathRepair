N,Q=map(int,input().split())
S=input()
TD=[]
for q in range(Q):
	TD.append(list(map(str,input().split())))
L=S[:]
R=S[::-1]
lw=0
rw=0
ansl = 0
ansr = 0
for q in range(Q)[::-1]:
	if TD[q][1] == 'L': 
		if TD[q][0] == L[lw]: #now word is OK
			ansl = max(ansl, lw+1)
			if lw+1 == N: #all clear
				break
			else:
				lw += 1
		if rw>0: 
			if TD[q][0] == R[rw-1]: #before word is wrong
				ansr = max(ansr-1, 0)
				rw -=1
	if TD[q][1] == 'R':
		if TD[q][0] == R[rw]: #now word is OK
			ansr = max(ansr, rw+1)
			if rw+1 == N: #all clear
				break 
			else:
				rw += 1
		if lw>0: 
			if TD[q][0] == L[lw-1]: #before word is wrong
				ansl = max(ansl-1, 0)
				lw -=1


print(max(0,N-(ansr+ansl)))