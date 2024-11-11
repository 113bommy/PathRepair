k = int(input())
a = [1, 2, 3, 4, 5, 6, 7, 8, 9]

for i in range(k):
    if a[i] % 10 != 0:
        a.append(10*a[i] + a[i] % 10 - 1)
    a.append(10*a[i] + a[i] % 10)
    if a[i] % 10 != 9:
        a.append(10*a[i] + a[i] % 10 + 1)

print(a[k - 1])
