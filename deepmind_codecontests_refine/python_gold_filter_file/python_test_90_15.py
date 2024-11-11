t = int(input())
for _ in range(t):
    x, y = map(int, input().split())
    n = -1
    if x > y:
        n = x + y
    elif x == y:
        n = x
    else:
        q = max((y - 2 * x), 0) // x + 1
        n = (q * x + y) // 2
    print(n)
    # if n % x == y % n:
    #     print("YES")
