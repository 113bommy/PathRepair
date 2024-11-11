for _ in range(int(input())):
    n, x, y = map(int, input().split())
    min_ans = max(min(n, x + y - n + 1), 1)
    max_ans = min(x + y - 1, n)
    print(min_ans, max_ans)
