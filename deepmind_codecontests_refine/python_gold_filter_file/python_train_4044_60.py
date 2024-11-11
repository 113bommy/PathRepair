N = int(input())
L = [2, 1]
for i in range(N):
  L.append(L[-1]+L[-2])
print(L[N])