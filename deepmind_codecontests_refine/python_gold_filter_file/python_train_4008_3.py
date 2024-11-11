inp = lambda : map(int, input().split())
n, w = inp()
a = sorted([*inp()])
print(min(w, min(a[n] / 2, a[0]) * n * 3))
