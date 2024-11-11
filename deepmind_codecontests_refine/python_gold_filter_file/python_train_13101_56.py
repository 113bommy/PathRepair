n, c, k = map(int, input().split()); a = [int(input()) for _ in range(n)]
a.sort(); t = a[0]+k; m = 0; x = 1
for i in range(n):
    if a[i] > t or m == c: t = a[i]+k; m = 1; x += 1
    else: m += 1
print(x)