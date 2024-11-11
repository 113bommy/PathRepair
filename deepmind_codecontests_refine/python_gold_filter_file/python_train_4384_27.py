w, h, k = map(int, input().split())

ans = 0

for _ in range(k):
    ans += w * h - (w - 2) * (h - 2)
    w -= 4
    h -= 4

print(ans)
