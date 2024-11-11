k = int(input())

if k <= 2 * 10**16:
    n = 2
    if k % 2 == 0:
        a = [k // 2 + 1, k // 2 + 1]
    else:
        a = [k // 2 + 3, k // 2]
else:
    n = 50
    a = [k // n + n - 1 for _ in range(50)]
    for i in range(k % n):
        for j in range(n):
            if j == i:
                a[j] += n
            else:
                a[j] -= 1
print(n)
print(' '.join(map(str, a)))