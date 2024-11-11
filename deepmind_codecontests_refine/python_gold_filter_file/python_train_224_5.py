t = int(input())
for p in range(t):
    n = int(input())
    l = r = k = 0
    b = False
    if n < 2:
        l, r = map(int, input().split())
        print(0)
    else:
        for i in range(n):
            li, ri = map(int,input().split())
            if l == 0 and r == 0:
                l = li
                r = ri
            else:
                if ri >= l and li <= r:
                    k += 1
                    if b == False:
                        if ri < r: r = ri
                        if li > l: l = li
                elif ri > l and li > r:
                    if b == False:
                        l = r
                    r = li
                    b = True
                elif ri < l:
                    if b == False:
                        r = l
                    l = ri
                    b = True
        if k < n-1:
            print(r-l)
        else:
            print(0)