n, t, c = map(int, input().split())
a = [int(x) for x in input().split()]
ans = 0
cnt = 0
for i in a:
    if i <= t:
        cnt += 1
    else:
        cnt = 0

    if cnt >= c:
        ans += 1
print(ans)
