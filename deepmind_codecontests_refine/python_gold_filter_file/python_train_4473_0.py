while True:
    n, m, k = (int(s) for s in input().split())
    if (n, m, k) == (0, 0, 0):
        break

    t_out = [0.] * (k + m + 1)
    tl_east = [0.] * (k + m + 1)
    tl_west = [0.] * (k + m + 1)

    for i in range(n):
        xi, li, fi, di, udi = (int(s) for s in input().split())
        if not udi:
            tl_east[xi] = li / fi
            tl_west[xi] = li / di
            t_out[xi] = -tl_west[xi]
        else:
            tl_east[xi] = li / di
            tl_west[xi] = li / fi

    for i in range(m):
        vi = int(input())
        t_out[0] = max(t_out[1] - tl_east[1], i / vi)
        for j in range(1, k + m):
            t_out[j] = tl_east[j] + max(t_out[j - 1] + 1 / vi,
                                        t_out[j] + tl_west[j],
                                        t_out[j + 1] - tl_east[j + 1])

    print(t_out[k])