T = int(input())
for t in range(T):
    n = int(input())
    p = list(map(int, input().split()))
    same = []
    prev_p = p[0]
    cur = 1
    for i in range(1, n):
        pi = p[i]
        if pi == prev_p:
            cur += 1
        else:
            same.append(cur)
            cur = 1
        prev_p = pi
    if cur:
        same.append(cur)
        cur = 0
    # print("same : ", same)
    g = same[0]
    s = 0
    b = 0
    cur_s = g
    maxi = n // 2
    res = True
    cur_index = 1
    while cur_index < len(same):
        if cur_s > maxi:
            res = False
            break
        if s > g:
            #  We try to add to b
            q = same[cur_index]
            if cur_s + q > maxi:
                if g > s or g > b:
                    res = False
                break
            b += q
            cur_s += q
            cur_index += 1
        else:
            # We try to add to s
            q = same[cur_index]
            if cur_s + q > maxi:
                res = False
                break
            s += q
            cur_s += q
            cur_index += 1
    if not (res) or g >= s or g >= b:
        print("0 0 0")
    else:
        print("%s %s %s" % (g, s, b))
