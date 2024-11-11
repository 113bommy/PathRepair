for case in range(int(input())):
    flag = True
    n, x, m = [int(x) for x in input().split()]
    
    L = 99999999999
    R = 0
    for i in range(m):
        l, r = [int(x) for x in input().split()]
        if flag and l <= x <= r:
            L = min(l, L)
            R = max(r, R)
            flag = False
        elif l <= R and r >= L:
            L = min(L, l)
            R = max(R, r)
    # print(L, R)
    if flag:
        print(1)
    else:
        print(R-L+1)

    # print(R-L+1)