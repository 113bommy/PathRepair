x, y = [int(i) for i in input().split()]
z = [int(i) for i in input().split()]
a = z[0]
b = 0
for i in range(1, x):
    if y > a + z[i]:
        b += y-a-z[i]
        z[i] += y-a-z[i]
    a = z[i]
print(b)
for i in z:
    print(i, end=' ')
