t = int(input())
for i in range(t):
    n, k = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    seta = set(a)
    if k<len(seta):
        print(-1)
    else:
        print(n*k)
        appender = list(seta)
        for j in range(k-len(seta)):
            appender.append(1)
        for j in range(n):
            for z in appender:
                print(z, end=" ")
        print("")
