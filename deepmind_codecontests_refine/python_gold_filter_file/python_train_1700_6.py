import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    x = input()
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    t = list(map(int,input().split()))

    ac = {}
    for i in range(k):
        ac[a[i]] = t[i]

    temp = [1e10]*n
    min_temp = 1e10
    for i in range(1,n+1):
        if i in ac:
            min_temp = min(min_temp,ac[i])

        temp[i-1] = min(temp[i-1],min_temp)

        min_temp += 1

    min_temp = 1e10
    for i in range(n, 0, -1):
        if i in ac:
            min_temp = min(min_temp, ac[i])

        temp[i - 1] = min(temp[i - 1], min_temp)

        min_temp += 1

    print(*temp)