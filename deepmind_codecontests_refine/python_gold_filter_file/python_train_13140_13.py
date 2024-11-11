for _ in range(int(input())):
    n, a = input(), sorted(map(int, input().split()), reverse=True)
    print(*(a))
