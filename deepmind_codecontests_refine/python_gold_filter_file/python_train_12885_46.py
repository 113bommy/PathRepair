ret = 0
S = input()
T = input()
print(len([S[i] for i in range(len(S)) if S[i] != T[i]]))