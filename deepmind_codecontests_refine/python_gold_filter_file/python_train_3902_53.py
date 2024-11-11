n, m = map(int, input().split())
a = []
k = 0
for i in range(n):
    a.append(['#'] * m)

for i in range(n):
    if i % 2 == 1:
        k += 1
    for j in range(m):
        if i % 2 == 1 and k % 2 == 0 and j != 0 or i % 2 == 1 and k % 2 == 1 and j != m-1:
            a[i][j] = '.'

for i in range(n):
    for j in range(m):
        print(a[i][j], end="")
    print()
