n, m = map(int, input().split())
m1, m2 = map(int, input().split())
for i in range(n-1):
    a, b = map(int, input().split())
    if m1 / m2 > a / b:
        m1, m2 = a, b
print(m1 * m / m2)