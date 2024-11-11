a, b, c, d = [int(x) for x in input().split()]
n = a + b + c + d

if a > b + 1 or d > c + 1:
    print("NO")
elif a == b + 1:
    if c > 0 or d > 0:
        print("NO")
    else:
        ls = [0, 1] * b + [0]
        print("YES")
        print(*ls)
elif d == c + 1:
    if a > 0 or b > 0:
        print("NO")
    else:
        ls = [3, 2] * c + [3]
        print("YES")
        print(*ls)
else:
    ls1 = [0, 1] * a
    ls2 = [2, 3] * d
    b -= a
    c -= d
    if b == c:
        print("YES")
        print(*ls1, *([2, 1] * c), *ls2)
    elif b > c:
        if b == c+1:
            print("YES")
            print(1, *ls1, *([2, 1] * c), *ls2)
        else:
            print("NO")
    else:
        if c == b + 1:
            print("YES")
            print(*ls1, *([2, 1] * b), *ls2, 2)
        else:
            print("NO")
