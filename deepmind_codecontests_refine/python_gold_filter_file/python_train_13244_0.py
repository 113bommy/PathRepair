for _ in range(int(input())):
    n, x = list(map(int, input().split()))
    ar = list(map(int, input().split()))
    num = (x + max(ar) - 1) // max(ar)
    if num == 1 and x not in ar:
        num = 2
    print(num)