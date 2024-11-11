for _ in range(int(input())):
    x, y, n = map(int, input().split())
    if(n%x == y):
        print(n)
    elif(n%x < y):
        print(n - x + (y - n%x))
    else:
        print(n - (abs(n%x - y)))