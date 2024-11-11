for j in range(int(input())):
    b = int(input())
    a = sorted(list(map(int, input().split())))
    s = 1000
    #print(a)
    for i in range(1, len(a)):
        s = min(a[i] - a[i - 1], s)
    print(s)