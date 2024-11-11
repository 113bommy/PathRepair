n = int(input())
m = int(input())
a = [0] * n
s = 0
ma = 0
for i in range(n):
    a[i] = int(input())
    ma = max(a[i], ma)
    s += a[i]
print(max((s + m + n - 1) // n, ma), ma + m)