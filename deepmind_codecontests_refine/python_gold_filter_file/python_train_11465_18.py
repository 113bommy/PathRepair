def check(a, b):
    return a*b < a+b

def solve(n):
    if n == 0:
        return 0, 0
    if n >= 1 and n <= 3:
        return None
    
    eps = 10**(-10)
    l, r = n/2, n
    while r - l > eps:
        x =  (l+r)/2
        if check(x, n-x):
            r = x
        else:
            l = x
    x = (l+r)/2
    return x, n-x

n = int(input())
for i in range(n):
    d = int(input())
    try:
        a, b = solve(d)
        print("Y %.9f %.9f" % (a, b))
    except Exception:
        print("N")
