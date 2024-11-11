n = int(input())

for i in range(n + 1):
    row = ''
    row += ' ' * (2 * (n - i))
    for j in range(i + 1):
        # if i != 0:
        #     row += str(j) + ' '
        # else:
        #     row += str(j)
        row += str(j) if i == 0 else str(j) + ' '
    for k in range(i - 1, -1, -1):
        # if k != 0:
        #     row += str(k) + ' '
        # else:
        #     row += str(k)
        row += str(k) if k == 0 else str(k) + ' '
    print(row)

for i in range(n - 1, -1, -1):
    row = ''
    row += ' ' * (2 * (n - i))
    for j in range(i + 1):
        # if i != 0:
        #     row += str(j) + ' '
        # else:
        #     row += str(j)
        row += str(j) if i == 0 else str(j) + ' '
    for k in range(i - 1, -1, -1):
        # if k != 0:
        #     row += str(k) + ' '
        # else:
        #     row += str(k)
        row += str(k) if k == 0 else str(k) + ' '
    print(row)
