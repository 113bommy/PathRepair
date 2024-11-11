n = int(input())
x, h = 0, 1
a = [[0, 0]]*n
for i in range(0, n):
    a[i] = list(map(int, input().split(" ")))
t, r = a[0][x], 1
for i in range(1, n):
    # left
    if a[i][x]-a[i][h] > t:
        t, r = a[i][x], r+1
    elif i == n-1 or a[i][x]+a[i][h] < a[i+1][x]:
        t, r = a[i][x]+a[i][h], r+1
    else:
        t = a[i][x]
print(r)
