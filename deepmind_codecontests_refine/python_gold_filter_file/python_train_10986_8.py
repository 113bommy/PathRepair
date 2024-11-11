n = int(input())
t = list(map(int, input().split()))
a, b = [0] * n, [0] * n
for i in range(1, n):
    if t[i] >= t[i - 1]: a[i] = a[i - 1] + 1
    if t[- i] <= t[- 1 - i]: b[- i - 1] = b[- i] + 1
print(max((a[i] + b[i] + 1) for i in range(n)))
