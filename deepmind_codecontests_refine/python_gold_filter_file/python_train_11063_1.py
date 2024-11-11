for _ in range(int(input())):
    leng = int(input())
    array = list(map(int, input().split()))
    zero = 0
    one = 0
    for i in array:
        if i == 1:
            one += 1
        else:
            zero += 1
    if zero >= leng // 2:
        print(leng // 2)
        print("0 " * (leng // 2))
    else:
        if (leng // 2 )  % 2 == 0:
            print(leng // 2)
            print("1 " * (leng // 2))
        else:
            print(leng // 2 + 1)
            print("1 " * (leng // 2 + 1))