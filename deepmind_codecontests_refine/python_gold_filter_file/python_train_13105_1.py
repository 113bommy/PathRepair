h, r = map(int, input().split())
if h + r < 0:print(-1)
else:print(0 if h + r == 0 else 1)
