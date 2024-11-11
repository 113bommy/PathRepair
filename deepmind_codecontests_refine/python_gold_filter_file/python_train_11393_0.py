A = int(input())
T = A
x = 0
while (A % 12 == 0):
    A = A // 12
    x = x + 1
b = [0] * 1000
b[1] = 2
b[2] = 13
for i in range(3, 606):
    b[i] = 13 * b[i - 1] - 12 * b[i - 2]
y = 1
while (b[y] < A):
    y = y + 1
if (b[y] != A):
    print("NO")
else:
    print("YES\n1")
    t = 2 * x + y
    print(t)
    c = [0] * 1000
    d = 0
    for i in range((t - 1) // 2 + 1):
        if (i != x and t - 2 * i != 0):
            c[d] = b[t - 2 * i] * 12 ** i
            d = d + 1
    print(d)
    for i in range(d):
        print(c[d - i - 1])
