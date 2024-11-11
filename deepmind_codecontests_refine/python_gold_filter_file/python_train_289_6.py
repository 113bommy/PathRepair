S = input()
L = len(S)
Truth = 0

for j in range(0, 8):
	if S[0:j] + S[L- 7 +j:] == "keyence":
		Truth = 1

if Truth ==1:
	print("YES")
else:
	print("NO")