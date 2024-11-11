n, m = [int(s) for s in input().split()]
a = []
b = []
for i in range(n):
    a.append([int(s) for s in input().split()])

for i in range(n):
    b.append([int(s) for s in input().split()])

diagsa = []
diagsb = []


for i in range(n-1):
    k = i
    j = 0
    diagsa.append([])
    diagsb.append([])
    while j < m and k > -1:
        diagsa[i].append(a[k][j])
        diagsb[i].append(b[k][j])
        j = j + 1
        k = k - 1
    diagsa[i].sort()
    diagsb[i].sort()

for j in range(m):
    k = j
    i = n-1
    diagsa.append([])
    diagsb.append([])
    while k < m and i > -1:
        diagsa[(n-1)+j].append(a[i][k])
        diagsb[(n-1)+j].append(b[i][k])
        i = i - 1
        k = k + 1
    diagsa[(n-1)+j].sort()
    diagsb[(n-1)+j].sort()

for i in range(len(diagsa)):
    if diagsa[i] != diagsb[i]:
        print("NO")
        break
else:
    print("YES")