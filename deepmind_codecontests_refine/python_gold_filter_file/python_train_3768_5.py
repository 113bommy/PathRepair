t = int(input())
while t:
    x = int(input())
    y = input()
    lis = [int(n) for n in y.split()]
    s = sum(lis)
    a = x - (s % x)
    if a != x:
        print((s+a)//x)
    else:
        print(s//x)
    t -= 1
