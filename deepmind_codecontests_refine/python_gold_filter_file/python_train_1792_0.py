
x=input()

ans = -1

L = 0
R = len(x)-1

while L < R:

    Lval = x[L]
    Rval = x[R]
    if Lval != Rval:
        ans = 0
        break

    Llen = 0
    while L < len(x) and x[L] == Lval:
        L += 1
        Llen += 1
    Rlen = 0
    while R >= 0 and x[R] == Rval:
        R -= 1
        Rlen += 1
    if Llen + Rlen < 3:
        ans = 0
        break

        
if L-R-1 >= 2:
    print(str(L-R))
else:
    print(str(0))