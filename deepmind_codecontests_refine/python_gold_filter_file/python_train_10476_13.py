S = input()
A = 0
for i in range(len(S)):
	for j in range(i + 1, len(S)):
		if S[i] == "Q" and S[j] == "A":
			A += S[j + 1:].count('Q')
print(A)