from collections import*
N,*A=map(int,open(0).read().split())
A.sort()
C=Counter(A)
s=0
for a in A[::-1]:
	if C[a]:
		C[a]-=1
		b=2**a.bit_length()-a
		if C[b]:
			C[b]-=1
			s += 1
print(s)