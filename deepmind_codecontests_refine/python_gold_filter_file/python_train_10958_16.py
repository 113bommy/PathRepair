cases = int(input())
while cases:
    cases -= 1
    zero, one, two = map(int, input().split())
    zero2, one2, two2 = map(int, input().split())

    ans = 0
    two_mn = min(two, one2)
    ans += (two_mn * 2)

    one2 -= two_mn
    two -= two_mn

    rem = two2 - (two+zero)

    ans -= max(rem, 0) * 2

    print(ans)








