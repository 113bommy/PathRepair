n = int(input())
for i in range(n):
    l = int(input())
    cur = [int(k) for k in input().split()]
    Min = cur[1]
    Max = cur[0]
    for i2 in range(l-1):
        cur = [int(k) for k in input().split()]
        Min = min(cur[1], Min)
        Max = max(cur[0], Max)
    print(max(Min, Max) - Min)