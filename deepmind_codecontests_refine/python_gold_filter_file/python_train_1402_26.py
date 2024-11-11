l, r = [int(x) for x in input().split()]
if r - l <= 1:
    print(-1)
else:
    if l % 2 == 0:
        print(l, l + 1, l + 2)
    elif r - l > 2:
        print(l + 1, l + 2, l + 3)
    else:
        print(-1)
