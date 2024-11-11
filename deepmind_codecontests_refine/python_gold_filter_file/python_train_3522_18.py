n = int(input())
station = [tuple(map(int, input().split())) for _ in range(n-1)]

for i in range(n):
    res = 0
    for j in range(i, n-1):
        c, s, f = station[j]
        res += max(s - res, (res+f-1)//f*f - res) + c
    print(res)
