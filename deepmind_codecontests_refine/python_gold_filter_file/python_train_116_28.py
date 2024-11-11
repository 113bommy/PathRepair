n, a = int(input()), input()
for i in range(n - 1):
    if a[i] > a[i + 1]:
        print('YES', i + 1, i + 2)
        break
else:
    print('NO')