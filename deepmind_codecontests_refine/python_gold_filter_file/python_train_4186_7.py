t = int(input())
for te in range(t):
    n = int(input())
    a = input()
    ans = n
    for i in range(n):
        if a[i] == '1': ans = max(ans, 2 * max(i + 1, n - i))
    print(ans)

