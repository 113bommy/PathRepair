def f(a, b):
    if a * b == 0:
        return 0
    res = f(min(a, b), max(a, b) % min(a, b)) + 2 * min(a, b) * (max(a,b)//min(a, b))
    if(max(a, b) % min(a, b) == 0):
        res -= min(a, b)
    return res

n, x = map(int, input().split())
res = n + f(n - x, x)
print(res)
