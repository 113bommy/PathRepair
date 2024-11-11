t = int(input())
while t:
    n,m = map(int, input().split())
    if n == 1:
        print(0)
    elif n < 3:
        print(m)
    else:
        print(m*2)
    t -= 1
