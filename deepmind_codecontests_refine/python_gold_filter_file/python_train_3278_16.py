a = list(map(int, '00' + input()))
n = len(a)


for i in range(n - 1):
    for j in range(i + 1, n - 1):
        for k in range(j + 1, n):
            if (a[i] * 100 + a[j] * 10 + a[k]) % 8 == 0:
                print('YES')
                print(a[i] * 100 + a[j] * 10 + a[k])
                exit()

print('NO')