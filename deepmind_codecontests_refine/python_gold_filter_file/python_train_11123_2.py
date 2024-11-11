H, W, h, w = map(int, input().split())
if H % h == 0 and W % w == 0:
    print('No')
    exit()
rem = H * W - (H - H % h) * (W - W % w)
x = (H // h * W // w) // rem + 1
a = [[x] * W for _ in range(H)]
for i in range(h-1, H, h):
    for j in range(w-1, W, w):
        a[i][j] = -(h * w - 1) * x - 1
print('Yes')
for row in a:
    print(*row)
