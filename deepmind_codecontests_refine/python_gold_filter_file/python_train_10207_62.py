while True:
    (H, W) = [int(x) for x in input().split()]
    if H == W == 0:
        break

    print(('#' * W + '\n') * H)