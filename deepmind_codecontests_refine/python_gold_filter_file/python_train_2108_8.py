for _ in range(int(input())):
    n = int(input())

    ans = []
    prev = 1
    m = 1
    while m != n:
        if (n - m) >= (4 * prev):
            curr = 2 * prev
        elif (prev <= (n - m)) and ((n - m) <= (2 * prev)):
            curr = n - m
        else:
            curr = (n - m) // 2
        m += curr
        ans.append(str(curr - prev))
        prev = curr

    print(len(ans))
    print(' '.join(ans))