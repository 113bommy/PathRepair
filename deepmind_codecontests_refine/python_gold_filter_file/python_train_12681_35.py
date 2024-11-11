S = input()
T = input()
X,Y = len(S),len(T)
L = [[0 for _ in range (Y+1)] for _ in range (X+1)]
for i in range (X):
  for j in range (Y):
    if S[i] == T[j]:
      L[i+1][j+1] = L[i][j]+1
    else:
      L[i+1][j+1] = max(L[i][j+1] , L[i+1][j] , L[i+1][j+1])
K = ''
while X*Y:
  if S[X-1] == T[Y-1]:
    K += S[X-1]
    X -= 1
    Y -= 1
  else:
    if L[X-1][Y] > L[X][Y-1]:
      X -= 1
    else:
      Y -= 1
print(K[::-1])