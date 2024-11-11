def ans(wh, u1d1, u2d2):
    w, h = wh[0], wh[1]
    u1, d1 = u1d1[0], u1d1[1]
    u2, d2 = u2d2[0], u2d2[1]
    while h >= 0:
        w += h
        if(h == d1):
            w -= u1
        if(h == d2):
            w -= u2
        h -= 1
        if(w < 0):
            w = 0
    return(w)

if __name__ == '__main__':
    wh = list(map(int, input().strip().split()))
    u1d1 = list(map(int, input().strip().split()))
    u2d2 = list(map(int, input().strip().split()))
    print(ans(wh, u1d1, u2d2))