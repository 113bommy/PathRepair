t = int(input())
for x in range(t):
    # print(x + 1)
    n = int(input())
    ls = list(map(int, input().split()))
    od = 0
    for i in ls:
        if i % 2 == 0:
            print(1)
            print(ls.index(i) + 1)
            break
        else:
            od += 1
    if od == n and n >= 2:
        print(2)
        print(1, 2)
    elif od == n and n % 2 != 0:
        print(-1)
        # print(ls)/
