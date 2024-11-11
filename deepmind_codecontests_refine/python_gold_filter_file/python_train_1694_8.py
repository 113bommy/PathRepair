T = int(input())

def f(i, c, x, y):
    if c%2:
        m = a[n-y-i-1]
    else:
        m = a[x+i]
    if c%2:
        return not m
    else:
        return m


for test in range(T):
    n = int(input())
    a = [bool(int(u)) for u in input()]
    b = [bool(int(u)) for u in input()]
    ans = []
    c = 0
    x = 0
    y = 0
    for i in range(n):
        if f(n-1-i, c, x ,y) == b[n-1-i]:
            continue
        else:
            if f(0, c, x, y) == b[n-1-i]:
                ans.append(1)
            ans.append(n-i)
            c+=1
            if c%2:
                y = i-x
            else:
                x = i-y
    print(len(ans), *ans)
