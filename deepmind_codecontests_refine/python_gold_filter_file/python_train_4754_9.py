from copy import copy

a = list(map(int, input().split()))

ans = 0
for i in range(14):
    b = copy(a)
    b[i] = 0

    for j in range(1, 14 + 1):
        b[(i + j) % 14] += (a[i] - 1) // 14 + ((a[i] - 1) % 14 + 1 > j - 1)

    ans = max(ans, sum(el * (el % 2 == 0) for el in b))

print(ans)
