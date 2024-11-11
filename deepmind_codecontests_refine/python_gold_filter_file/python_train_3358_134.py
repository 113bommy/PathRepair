for _ in range(int(input())):
    n = int(input())
    flag = 0
    a = []
    for i in range(0, n//2):
        if flag == 0:
            a.append(1000)
            a.append(1000)
            flag = 1
        else:
            a.append(222)
            a.append(222)
            flag = 0
    if n & 1:
        a.append(1)
    print(*a)
