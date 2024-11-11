for i in range(int(input())):
    x, y, z = map(int, input().split())
    n = z //x
    if n*x+y<= z:
        print(n * x + y)
    else:
        print((n-1)*x+y)