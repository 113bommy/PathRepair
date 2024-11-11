n, x = map(int, input().split())
*a, = map(int, input().split())
a.sort()
ans = 0
for i in a[:-1]:
    if x >= i:
        x -= i
        ans += 1
ans += a[-1] == x
print(ans)