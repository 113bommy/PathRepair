for _ in range(int(input())):
    l=[int(x) for x in input().split()]
    l.sort()
    print(l[-1]+l[0])