import sys
S = input()
L = len(S)
if S[0] == S[1]:
    print(1, 2)
    sys.exit()
if L == 2:
    print(-1, -1)
    sys.exit()
ansL = -1
ansR = -1
for i in range(2, L):
    if S[i-1] == S[i]:
        ansL = i
        ansR = i+1
        break
    if S[i-2] == S[i]:
        ansL = i-1
        ansR = i+1
        break
print(ansL, ansR)
