t = int(input())

for x in range(t):
    n = int(input())
    if n == 0:
        continue
    numbers = list(map(int, input().split()))
    all_same = 1
    a_pair = -1
    thing = numbers[0]
    for i in range(n):
        if numbers[i] != thing:
            all_same = 0
        if numbers[i] == numbers[(i + 1) % n]:
            a_pair = i
    if all_same:
        print(1)
        for i in range(n):
            print(1, end=' ')
        print()
    elif n % 2 == 0:
        print(2)
        a = 0
        for i in range(n):
            print(a + 1, end=' ')
            a = 1 - a
        print()
    else:
        if a_pair != -1:
            print(2)
            a = 0
            for i in range(n):
                print(a + 1, end=' ')
                if i != a_pair:
                    a = 1 - a
            print()
        else:
            print(3)
            a = 0
            for i in range(n-1):
                print(a + 1, end=' ')
                a = 1 - a
            print(3, end='')
            print()
