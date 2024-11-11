t = int(input())
for _ in range(t):
    n, s, k = map(int, input().split())
    x = list(map(int, input().split()))
    for i in range(max(s, n - s) + 1):
        r = s + i
        if r <= n and r not in x:
            print(abs(s - r))
            break
        r = s - i
        if r > 0 and r not in x:
            print(abs(s - r))
            break
