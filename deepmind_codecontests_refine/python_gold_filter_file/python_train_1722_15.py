n, k = map(int, input().split())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
l = 0
r = max(b) + k + 1
while r - l > 1:
    ans = (r + l) // 2
    x = 0
    for i in range(n):
        x += max(a[i] * ans - b[i], 0)
    # print(x, ans)
    if x <= k:
        l = ans
    else:
        r = ans
print(l)