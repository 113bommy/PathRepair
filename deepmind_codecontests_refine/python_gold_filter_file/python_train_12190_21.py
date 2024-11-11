def scanf(obj=list, type=int):
    return obj(map(type, input().split()))
n, m = scanf()
ans = 0
w = (n + 1) // 2
for i in range(m):
    x, d = scanf()
    f = lambda t: (d * (t - 1) * t // 2
                   + d * (n - t) * (n - t + 1) // 2)
    temp = max(f(w), f(1))
    if n != 1: temp = max(temp, f(w + 1))
    ans += temp + n * x
print('%.10f' % (ans / n))