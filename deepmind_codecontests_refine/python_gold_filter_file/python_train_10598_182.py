r,D,x = map(int, input().split())

for _ in range(10):
    x = x * r - D
    print(x)