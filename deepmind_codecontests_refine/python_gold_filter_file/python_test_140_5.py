import math

tst = int(input())
result = []

for i in range(tst):
    n = int(input())
    x = 0
    for i in range(1,int(math.sqrt(n))+1):
        if i * i <= n:
            x += 1
        if i * i * i <= n:
            x += 1
        if i * i * i * i * i * i <= n:
            x -= 1

    result.append(x)





for i in range(tst):
    print(result[i])


