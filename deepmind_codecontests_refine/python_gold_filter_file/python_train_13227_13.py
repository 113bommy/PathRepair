n,m = map(int,input().split())
a = []; b= [];
for i in range(n): a.append(list(map(int,input().split())))
for i in range(m): b.append(int(input()))
for i in range(n):
    c = 0
    for j in range(m):
        c += a[i][j]*b[j]
    print(c)

