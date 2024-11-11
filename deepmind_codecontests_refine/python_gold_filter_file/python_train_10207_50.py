while True:
    h, w = [int(i) for i in input().split()]
    if w == h == 0:
        break
    print(("#" * w + "\n")*h)

