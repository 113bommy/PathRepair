n, m = map(int, input().split())
[print(a.count(str(i + 1))) for a in [sum([input().split() for _ in range(m)], [])] for i in range(n)]
