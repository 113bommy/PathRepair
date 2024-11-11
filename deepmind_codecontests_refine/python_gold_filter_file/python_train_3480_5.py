k, a, b, v = map(int, input().split())
cnt = 1
while True:
    if b + 1 - k < 0:
        use_b = b + 1
    else:
        use_b = k

    if use_b != 0:
        max_or = use_b * v
    else:
        max_or = v
    if a - max_or > 0:
        cnt += 1
        b = b + 1 - use_b
        a -= max_or
    else:
        print(cnt)
        break