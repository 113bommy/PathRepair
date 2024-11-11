t = int(input())

for _ in range(t):

    n = int(input())
    a = [int(i) for i in input().split()]
    # sign = 1
    # for i in range(n-1):
    #     if abs(a[i]) <= abs(a[i+1]) and (a[i+1] - a[i]) * sign < 0:
    #         a[i] = abs(a[i])
    #         a[i+1] = sign * abs(a[i+1])
    #     elif (a[i+1] - a[i]) * sign < 0:
    #         a[i] = -1 * sign * abs(a[i])
    #         a[i + 1] = abs(a[i + 1])
    #     sign *= -1
    #
    # print(*a)

    sign = 1

    for i in range(n):
        a[i] = sign * abs(a[i])
        sign *= -1
    print(*a)