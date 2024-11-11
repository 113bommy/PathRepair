N = int(input())

ans = N
for i in range(N+1):
    x = 0
    y = i
    while y:
        x += y%6
        y //= 6
    y = N-i
    while y:
        x += y%9
        y //= 9
    ans = min(x, ans)

print(ans)