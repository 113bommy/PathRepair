n, m = [int(i) for i in input().split()]
a = []
b = []
s = ''
for i in range(n):
    name, ip = [j for j in input().split()]
    a.append((name, ip))

for i in range(m):
    command, ip = [j for j in input().split()]
    b.append((command, ip[0:-1]))

for i in range(m):
    for j in range(n):
        if b[i][1] == a[j][1]:
            print(b[i][0], b[i][1] + ';', '#' + a[j][0])
