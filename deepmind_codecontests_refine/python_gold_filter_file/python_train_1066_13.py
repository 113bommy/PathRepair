t = int(input())
while t:
    n, x, m = map(int, input().split())
    l_answ, r_answ = 10**9+1, -1
    l_last, r_last = -1, -1
    for op in range(m):
        l, r = map(int, input().split())
        if x >= l and x <= r:
            if l_answ > l:
                l_answ = l
            if r_answ < r:
                r_answ = r
        else:
            if r_answ != -1:
                if r >= l_answ and l <= r_answ:
                    if l_answ > l:
                        l_answ = l
                    if r_answ < r:
                        r_answ = r
        l_last, r_last = l, r
    if l_answ == 10**9+1 or r_answ == -1:
        print(1)
    else:
        print(r_answ-l_answ+1)
    t -= 1
