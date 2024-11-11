for i in range(int(input())):
    c = int(input())
    f = [int(i) for i in input().split()]
    if c == 1:
        if sum(f) % 2 == 1:
            print(-1)
        else:
            print(1)
            print(1)
    else:
        g = [i % 2 for i in f]
        if 0 in g:
            print(1)
            for i in range(len(g)):
                if g[i] == 0:
                    print(i + 1)
                    break
        else:
            print(2)
            print(1, 2)
