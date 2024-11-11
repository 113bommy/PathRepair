n = int(input())
x = int(input())
k = n % 6
a = [0] * 3
a[x] = 1


for i in range(n, n - k, -1):
    if i % 2 != 0:
        a[0], a[1] = a[1], a[0]
    else:
        a[1], a[2] = a[2], a[1]
for i in range(len(a)):
    if a[i]:
        print(i)
