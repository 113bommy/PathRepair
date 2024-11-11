N, D = map(int, input().split())
time = 0
floor = 1
num = 0
result = 0
for _ in [0]*N:
    t, f = map(int, input().split())
    if floor-1+f-1 <= t-time:
        result += num * (floor-1)
        num = 1
    elif abs(floor-f) <= t-time and num < D:
        result += num * abs(t-time)
        num += 1
    else:
        print(-1)
        break
    time, floor = t, f
else:
    result += num * (floor-1)
    print(result)