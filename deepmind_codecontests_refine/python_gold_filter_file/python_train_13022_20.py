n, m = map(int, input().split())
a = [0] * (m + 1)
for i in range(n):
    l, r = map(int, input().split())
    a[l - 1] = a[l - 1] + 1
    a[r] = a[r] - 1

cnt = tmp = 0
ans = [0] * m
for i in range(m):
    tmp = tmp + a[i]
    if tmp == 0:
        cnt = cnt + 1
        ans[i] = 1

print (cnt)
for i in range(m):
    if ans[i] != 0:
        print(i + 1, end=' ')
