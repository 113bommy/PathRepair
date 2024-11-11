import sys
a, b = map(int, sys.stdin.readline().split())
pp = pow(10,9) + 7
fib = [[0,1],[1,1]]

def MatDiv(a,b):
    res = [[0,0],[0,0]]
    res[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % pp
    res[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % pp
    res[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % pp
    res[1][1] = (a[1][0] * b[1][0] + a[1][1] * b[1][1]) % pp
    return res

def BinPow(x,p):
    if p == 1:
        return fib
    res = BinPow(x, p // 2)
    if p % 2 == 0:
        return MatDiv(res,res)
    else:
        return MatDiv(MatDiv(res,res),x)

tmp = BinPow(fib.copy(),a)
tmp2 = BinPow(fib.copy(),b)
print(((tmp[0][0] + tmp[0][1] + tmp2[0][0] + tmp2[0][1]) * 2 - 2) % pp)