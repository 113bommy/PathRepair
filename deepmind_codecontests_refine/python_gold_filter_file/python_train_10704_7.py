n = int(input())
S = [int(c == 'W') for c in list(input())]
L = [0]
for i in range(n):
    L.append(L[-1]+S[i])
R = [0]
for i in range(n-1, 0, -1):
    R.append(R[-1]+1-S[i])
R.reverse()
print(min([L[i]+R[i] for i in range(n)]))
