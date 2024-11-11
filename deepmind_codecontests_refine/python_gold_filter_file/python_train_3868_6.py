def solve(x):
    if x < 10:
        return x
    t = 1
    y = -1
    while t <= x:
        t *= 10
        y += 1
    t = t // 10
    if x == t:
        return 9 ** y
    a = x // t
    b = x % t
    c = a * solve(b)
    d = max(a - 1,  1) * 9 ** y   
    #print (x,  t,  a,  b,  c,  d) 
    return max(c,  d)

n = int(input())
r = solve(n)
print (r)