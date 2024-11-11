w, h, k = map(int, input().split())
res = 0
for i in range(k):
    if (min(w, h) == 1):
        res += max(w, h)
    else:
        res += 2 * (w + h) - 4
    w -= 4
    h -= 4

print(res)
