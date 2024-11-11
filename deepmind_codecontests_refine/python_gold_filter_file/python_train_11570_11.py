# https://vjudge.net/contest/319028#problem/F

n = int(input())

for i in range(n):
    t = int(input())
    result = 0
    for i in range(7, 1, -1):
        while t >= i:
            t -= i
            result += 1
    if t == 1:
        result += 1
    print(result)