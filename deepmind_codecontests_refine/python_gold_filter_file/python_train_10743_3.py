t = int(input())

for _ in range(t):
    n, m = map(int,input().split())

    weights = list(map(int, input().split()))

    if m < n or n==2: print(-1)

    else:
        res = 2* sum(weights)

        print(res)

        print(1, n)

        for i in range(1, n):
            print(i, i+1)