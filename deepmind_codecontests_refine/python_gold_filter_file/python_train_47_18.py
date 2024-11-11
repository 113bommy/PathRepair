n = int(input())

min_x = -2e9
x0, h0 = map(int, input().split())
ans = 0

for i in range(n-1):
    x, h = map(int, input().split())
    if x0-h0 > min_x:
        min_x = x0
        ans += 1
    elif x0+h0 < x:
        min_x = x0+h0
        ans += 1
    min_x = max(min_x, x0)
    x0, h0 = x, h
ans += 1

print(ans)
