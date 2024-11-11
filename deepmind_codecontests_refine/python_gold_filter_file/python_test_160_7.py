for _ in range(int(input())):
    n, m, rx, ry, cx, cy = map(int, input().split())
    if rx > cx:
        ans_x = 2 * (n - rx) + rx - cx
    else:
        ans_x = cx - rx
    if ry > cy:
        ans_y = 2 * (m - ry) + ry - cy
    else:
        ans_y = cy - ry
    print(min(ans_x, ans_y))