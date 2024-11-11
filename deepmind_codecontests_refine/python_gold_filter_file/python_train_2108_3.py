t = int(input())
for test_case in range(t):
    n = int(input())
    b = 1
    ans = []
    n -= 1
    while n > 0:
        if 4*b < n:
            ans.append(b)
            b *= 2
            n -= b
        elif 2 * b < n:
            ans.append((n-2*b)//2)
            ans.append((n-2*b)%2)
            n = 0
        else:
            ans.append(n-b)
            n = 0
    print(len(ans))
    print(*ans)