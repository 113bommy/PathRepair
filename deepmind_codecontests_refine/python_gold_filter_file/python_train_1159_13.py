n = int(input())
a = [int(x) for x in input().split()]
c, b, j = sorted(a), [0] * n, 0
for i in range(0, n - 1, 2):
    b[j] = c[i]
    b[n - 1 - j] = c[i + 1]
    j += 1
if n % 2 == 1:
    b[n // 2] = c[n - 1]
print(*b)
