l, r = map(int, input().split())
if  r - l >= 672:
    print(0)
else:
    print(min(i * j % 2019 for i in range(l, r + 1) for j in range(l, i)))