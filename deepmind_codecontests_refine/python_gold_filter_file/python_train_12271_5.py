for _ in range(int(input())):
    l = list(map(int, input().split()))
    l.sort()
    print('YES' if l[0]**2 + l[1] ** 2 == l[2] ** 2 else 'NO') 