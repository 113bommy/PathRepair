n, t, c = map(int, input().split())
lis = [int(x) for x in input().split()]
ans = 0
cnt = 0
for i in lis:
    if(i <= t):
        cnt += 1
    else:
        cnt = 0

    if(cnt >= c):
        ans += 1

print(ans)
