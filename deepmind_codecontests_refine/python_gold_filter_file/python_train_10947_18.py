T = int(input())
for i in range(T):
    n = int(input())
    ans = 0
    while n > 1:
        if n % 5 == 0:
            ans += 3
            n //= 5
        elif n % 3 == 0:
            ans += 2
            n //= 3
        elif n % 2 == 0:
            ans += 1
            n //= 2
        else:
            break
    if n > 1:
        print(-1)
    else:
        print(ans)