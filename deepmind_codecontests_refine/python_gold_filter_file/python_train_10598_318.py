r, D, x0 = map(int, input().split())
for i in range(10):
    x0 = r*x0-D
    print(x0)