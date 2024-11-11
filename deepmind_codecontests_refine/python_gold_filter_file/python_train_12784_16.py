n, x = [int(x) for x in input().split()]
k = 0
ans = 1
for li in input().split():
    k += int(li)
    ans += k <= x

print(ans)
