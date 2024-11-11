H, W = map(int, input().split())
ans = (H * W + 1) // 2
if H == 1 or W == 1:
    ans = 1
print(ans)