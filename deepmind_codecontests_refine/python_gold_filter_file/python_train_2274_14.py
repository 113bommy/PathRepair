n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

def f(l, s):
    return s if l % s == 0 else f(s, l % s)

z = f(a[-1], a[0])
for i in a:
    z = f(i, z)
if a[-1] >= k and k % z == 0:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')