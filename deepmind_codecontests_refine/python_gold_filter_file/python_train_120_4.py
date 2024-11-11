for _ in range(int(input())):
    a, b, c = [int(s) for s in input().split()]
    m = 0
    
    for x in range(a+1):
        for y in range(c // 2 + 1):
            if 2*x + y <= b:
                m = max(m, 3*x + 3*y)

    print(m)