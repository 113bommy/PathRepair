n = int(input())
x = int(input())
n = n % 6
for i in range(3):
    d = [0, 0, 0]
    d[i] = 1
    for j in range(n):
        if j % 2 == 0:
            d[0], d[1] = d[1], d[0]
        else:
            d[1], d[2] = d[2], d[1]

    for j in range(3):
        if d[j] == 1:
            if j == x:
                print(i)
                exit()