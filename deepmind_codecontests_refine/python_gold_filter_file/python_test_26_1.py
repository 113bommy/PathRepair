n = int(input())
for time in range(n):
    t = int(input())
    ans = 1
    for x in range(1, 2 * t + 1):
        if x != 2:
            ans = (ans * x) % 1000000007
    print(ans)
