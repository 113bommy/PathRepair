t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = ''
    ans = n - k + k-(k+1)//2
    for i in range(k+1, n+1):
        s += str(i) + ' '
    for i in range((k+1)//2, k):
        s += str(i) + ' '

    if n == 1:
        ans = 0
    print(ans)
    print(s)