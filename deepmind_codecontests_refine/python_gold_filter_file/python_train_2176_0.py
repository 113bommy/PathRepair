while True:
    try:
        s = input().strip()
    except:
        break
    i = 0
    cnt_joi, cnt_ioi = 0, 0
    while i < len(s) - 2:
        t = s[i:i + 3]
        if t == 'JOI':
            cnt_joi += 1
            i += 2
        elif t == 'IOI':
            cnt_ioi += 1
            i += 2
        elif t[2] == 'O':
            i += 1
        elif t[2] in 'IJ':
            i += 2
        else:
            i += 3
    print(cnt_joi)
    print(cnt_ioi)