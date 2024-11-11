def Solve():
    n, x, y = map(int, input().split(" "))
    n //= 2

    if (n == x or n == x - 1) and (n == y or n == y - 1):
        print("NO")
    else:
        print("YES")


Solve()
