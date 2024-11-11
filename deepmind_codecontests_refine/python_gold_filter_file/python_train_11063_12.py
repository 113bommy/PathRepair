t = int(input())

for _ in range(t):
    n = int(input())
    numbers = list(map(int,input().split(' ')))
    count_0 = 0
    count_1 = 0
    for i in numbers:
        if i == 0:
            count_0 += 1
        else:
            count_1 += 1

    if count_0 >= n/2:
        print(count_0)
        for i in range(count_0): print(0,end=' ')
    else:
        print(count_1 - count_1 % 2)
        for i in range(count_1 - count_1 % 2):print(1,end=' ')
    print('')