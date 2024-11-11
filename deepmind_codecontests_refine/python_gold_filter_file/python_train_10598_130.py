r, D, x = map(int, input().split())
for a in range(10):
    x = r * x - D
    print(x)