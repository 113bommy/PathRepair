for _ in range(int(input())):
    n, m, a, b = map(int, input().split())
    if n*a != m*b:
        print("NO")
    else:
        print("YES")
        t = "1"*a + "0"*(m-a)
        for i in range(n):
            print(t)
            t = t[m-a:] + t[:m-a]
