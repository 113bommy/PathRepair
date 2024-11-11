n, m = map(int, input().split())
M1 = []
M2 = []
for i in range(n):
 M1.append(list(map(int, input().split())))

for i in range(m):
 M2.append(int(input()))

for i in range(n):
 c = 0
 for s in range(m):
  c += M1[i][s] * M2[s]
 print(c)