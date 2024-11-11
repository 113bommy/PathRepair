a,b,c,d = map(int, input().split())

if a > b + 1 or d > c + 1:
    print("NO")
elif a == b + 1:
    if c == d == 0:
        print("YES")
        print('0 1 ' * b + ' 0')
    else:
        print("NO")
elif d == c + 1:
    if a == b == 0:
        print("YES")
        print('3 2 ' * c + ' 3')
    else:
        print("NO")
else:
    b -= a
    c -= d
    k = min(b,c)
    if abs(b-c) >= 2:
        print("NO")
    else:
        xb, xc = b - k, c - k
        ans = '1' * xb + '01' * a + '21' * k + '23' * d + '2' * xc
        print("YES")
        print(" ".join(ans))

