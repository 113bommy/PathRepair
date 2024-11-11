for _ in range(int(input())):
    n = int(input())
    s = list(map(int, input().split()))
    b = []
    if n%2:
        for i in range(0,n-3,2):
            b += [-s[i+1], s[i]]
        if s[-2]+s[-3] != 0:
            b += [-s[-1]]
            b += [-s[-1]]
            b += [s[-2]+s[-3]]
        elif s[-1]+s[-3] != 0:
            b += [-s[-2]]
            b += [s[-1]+s[-3]]
            b += [-s[-2]]
        else:
            b += [s[-1]+s[-2]]
            b += [-s[-3]]
            b += [-s[-3]]
    else:
        for i in range(0,n,2):
            b += [-s[i+1], s[i]]
    print(*b)
