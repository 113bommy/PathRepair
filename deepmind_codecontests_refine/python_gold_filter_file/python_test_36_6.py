import math

for t in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    x = sum(a)
    f = -1
    for j in range(2, int(math.sqrt(x))+1):
        if x % j == 0:
            f = 1
            break
    if f == 1:
        print(n)
        print(*[i for i in range(1, n + 1)])
    else:
        print(n - 1)
        arr = []
        t = 0
        for i in range(len(a)):
            if a[i]&1 and t == 0:
                t = 1
                continue
            else:
                arr.append(i+1)
        print(*arr)