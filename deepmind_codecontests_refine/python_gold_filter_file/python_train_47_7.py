n = int(input())
a = [[int(i) for i in input().split()] for j in range(n)]
x = [[0 for k in range(2)] for i in range(n)]
x[0][0] = a[0][0] - a[0][1]
x[0][1] = a[0][0]
c = n
for i in range(1, n - 1):
    if a[i][0] - a[i][1] > x[i - 1][1]:
        x[i][0] = a[i][0] - a[i][1]
        x[i][1] = a[i][0]
    elif a[i][0] + a[i][1] < a[i + 1][0]:
        x[i][0] = a[i][0]
        x[i][1] = a[i][0] + a[i][1]
    else:
        x[i][0] = x[i][1] = a[i][0]
        c -= 1
print(c)
