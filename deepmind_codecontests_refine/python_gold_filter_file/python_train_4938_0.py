n, v = map(int, input().split())
k = [[0, ' '], [0, ' ']]
c = [[0, ' ']]
sum = 0
vehicles = []

for i in range(n):
    q = input().split()
    if q[0] == '1':
        k += [[int(q[1]), i+1]]
    elif q[0] == '2':
        c += [[int(q[1]), i+1]]

k.sort(key=lambda a: a[0])
c.sort(key=lambda a: a[0])

for i in range(n):
    if c[-1][0] > k[-1][0] + k[-2][0]:
        if v >= 2:
            add = c[-1][0]
            vehicles.append(c[-1][1])
            c.pop()
            v -= 2
        elif v >= 1:
            add = k[-1][0]
            vehicles.append(k[-1][1])
            k.pop()
            v -= 1
    elif v >= 1:
        add = k[-1][0]
        vehicles.append(k[-1][1])
        k.pop()
        v -= 1
    sum += add
    if v == 0:
        break


print(sum)
for i in vehicles:
    print(i, end=' ')
