n, a, b = map(int, input().split())
h = list(map(int, input().split()))
h.sort(reverse=True)
res = h[a-1] - h[a]
if res > 0:
    print(res)
else:
    print(0)
