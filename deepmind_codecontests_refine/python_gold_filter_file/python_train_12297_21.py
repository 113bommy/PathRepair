q = int(input())
for i in range(q):
    l, r = (int(x) for x in input().split())
    if (l - r + 1) % 2 == 1:
        if (l + 1) % 2 == 0:
            print(-l - (r - l + 1) // 2)
        else:
            print(l + (r - l + 1) // 2)
    else:
        if (l + 1) % 2 == 0:
            print((r - l + 1) // 2)
        else:
            print(-(r - l + 1) // 2)