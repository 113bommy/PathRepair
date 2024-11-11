X, Y, Z, K =map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

AB = []
for i in range(X):
  for j in range(Y):
    AB.append(A[i] + B[j])
AB.sort(reverse=True)

ans = []
for i in range(min(K, len(AB))):
  for j in range(Z):
    ans.append(AB[i] + C[j])
ans.sort(reverse=True)

for i in range(K):
  print(ans[i])