N = int(input())
s = 0
for i in range(1, N):
  for j in range(i + 1, N + 1):
    if i + j + (N % 2) != N + 1:
      s+=1
print(s)
for i in range(1, N):
  for j in range(i + 1, N + 1):
    if i + j + (N % 2) != N + 1:
      print(i, j)
