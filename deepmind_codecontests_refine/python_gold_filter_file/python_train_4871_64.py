H, W = map(int, input().split())

if H == 1 or W == 1:
    print(1)
else:
    print((W * H + 1) // 2)