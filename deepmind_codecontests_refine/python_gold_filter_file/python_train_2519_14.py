for i in range(int(input())):
    a, b, n, S = list(map(int, input().split()))

    if (a*n + b < S):
        print("NO")
    else:
        x = S % n
        print("YES" if (x <= b) else "NO")
