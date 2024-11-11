S = list(input())
T = list(input())
if len(S) < len(T):
	print("UNRESTORABLE")
else:
	S = S[::-1]
	T = T[::-1]
	for i in range(len(S)-len(T)+1):
		if all (T[j] == S[i+j] or S[i+j] == '?' for j in range(len(T))):
			S[i:i+len(T)] = T
			S = S[::-1]
			print("".join(S).replace('?','a'))
			exit()
	print("UNRESTORABLE")