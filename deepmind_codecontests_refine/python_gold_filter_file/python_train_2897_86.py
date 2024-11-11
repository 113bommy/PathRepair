N=int(input())
S=[input()for _ in'_'*N]
z=0
for k in range(-N,0):
	for t in range(N*N):
		i=t//N
		j=t%N
		if S[i][j+k]!=S[j][i+k]:
			break
	else:
		z+=N
print(z)
