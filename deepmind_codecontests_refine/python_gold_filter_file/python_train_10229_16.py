T = int(input())
for f in range(T):
    x = 0
    a, b, n = map(int, input().split())
    p = True
    if a > b or a == b:
        Big = a
        Small = b
    else:
        Big = b
        Small = a

    while Big <= n and Small <= n:
        if p:
            Small += Big
            p = False
        else:
            Big += Small
            p = True
        x += 1
    print(x)