for _ in range(int(input())):
    c, s = map(int, input().split())
    if s < c:
        print(s)
    else:
        div = s//c
        mod = s % c
        ans = pow((div + 1), 2) * mod
        ans += pow(div, 2) * (c-mod)
        print(ans)