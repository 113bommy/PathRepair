for i in range(int(input())):
    a, b = map(int, input().split())
    lst = list(map(int, input().split()))
    if a == 2:
        print(-1)
    elif a >= 3:
        if b < a:
            print(-1)
            continue
        elif a == b:
            print(2*sum(lst))
            for c in range(1, a):
                print(c, c+1)
            print(a, 1)