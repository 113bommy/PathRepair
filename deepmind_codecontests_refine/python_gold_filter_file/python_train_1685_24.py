for _ in range(int(input())):
    n = int(input())
    data = [int(i) for i in input().split()]
    mx = [0] * n
    mx1 = 1 <<50
    for i in range(n-1, -1, -1):
        mx[i] = mx1
        mx1 = min(data[i], mx1)
    ans = 0
    for i in range(n):
        if data[i] > mx[i]:
            ans += 1
    print(ans)


