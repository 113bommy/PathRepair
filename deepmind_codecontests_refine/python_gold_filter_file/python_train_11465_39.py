def ii():
    return int(input())
def mi():
    return map(int, input().split())
def li():
    return list(mi())

for t in range(ii()):
    d = ii()
    D = d * d - 4 * d
    if D < 0:
        print('N')
        continue
    ans = (d - D ** 0.5) / 2
    print('Y {:.9f} {:.9f}'.format(d - ans, ans))
