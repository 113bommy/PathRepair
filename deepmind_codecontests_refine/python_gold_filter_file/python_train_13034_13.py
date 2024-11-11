for tc in range(int(input())):
    n = int(input())
    ls = list(map(int, input().split()))
    xr = 0
    sm = sum(ls)
    for e in ls:
        xr ^= e
    nadd = 2**50 + (sm%2)
    sm += nadd
    xr = 2 * (xr ^ nadd)
    #print(xr-sm)
    rem = (xr-sm)//2
    print(3)
    print(nadd, rem, rem)
