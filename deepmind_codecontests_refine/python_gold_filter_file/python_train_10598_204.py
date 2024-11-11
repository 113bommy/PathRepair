a, b, c = map(int, input().split())
for i in range(10):
    c = c*a - b
    print(c)