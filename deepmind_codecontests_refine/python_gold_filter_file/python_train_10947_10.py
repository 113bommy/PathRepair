q = int(input())
i = 0
while i < q:
    n = int(input())
    count = 0
    ans = True
    while n != 1:
        if n % 2 == 0:
            n = n // 2
            count += 1
        elif n % 3 == 0:
            n = (n // 3) * 2
            count += 1
        elif n % 5 == 0:
            n = (n // 5) * 4
            count += 1
        else:
            ans = False
            break
    print(count if ans else -1)
    i += 1
