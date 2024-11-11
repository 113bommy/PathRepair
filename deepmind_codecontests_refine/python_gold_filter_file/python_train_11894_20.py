for t in range(int(input())):
    n = int(input())
    if n <4:
        print(-1)
    else:
        a = [3, 1, 4, 2]
        for i in range(5, n+1):
            if i%2 != 0:
                a.append(i)
            else:
                a.insert(0, i)
        print(*a)

