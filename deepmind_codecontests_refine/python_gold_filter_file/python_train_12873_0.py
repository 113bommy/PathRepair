k, n, s, p = map(int, input().split())
l = -1
r = 10 ** 18
for i in range(1, 100000):
    if i * s >= n:
        number = i
        break
while r - l > 1:
    m = (r + l) // 2
    if (m * p) // (k) >= number:
        r = m
    else:
        l = m
print(r)