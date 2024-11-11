from math import log, ceil

n, f, l = [int(i) for i in input().split()]
try:
    a = 2 ** ceil(log(n, 2)) - 1
except Exception:
    pass

def fun(n, ind, depth):
    if n < 2:
        return [n]
    if n == 2:
        return [1, 0, 1]
    else:
        cnt = a // (2 ** depth)
        ind += cnt
        
        p1 = [cnt]
        p2 = [cnt]

        if (f < ind):
            p1 = fun(n // 2, ind - cnt, depth + 1)
        if (l > ind):
            p2 = fun(n // 2, ind + 1, depth + 1)
        
        return p1 + [n % 2] + p2

if n == 0:
    print(0)
else:   
    a = fun(n, 1, 1)
    if (n == 2):
        a = [1, 0, 1]
    cnt = 0
    i = 0
    #print(a)
    for j in range(len(a)):
        if (a[j] < 2):
            i += 1
        else:
            i += a[j]
        if (i > l):
            break
        if (a[j] == 1 and i >= f and i <= l):
            cnt += 1
            
    print(cnt)
