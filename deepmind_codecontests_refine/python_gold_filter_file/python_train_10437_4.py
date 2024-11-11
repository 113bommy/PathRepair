
test_cases = int(input())
for _ in range(test_cases):
    l = int(input())
    arr = [int(x) for x in input().split()]
    sign = -1
    if arr[0] >= 0:
        sign = 1
    for i in range(1, len(arr)):
        if sign == 1:
            if arr[i] >= 0:
                arr[i] = -arr[i]
            sign = -1
        elif sign == -1:
            if arr[i] <= 0:
                arr[i] = -arr[i]
            sign = 1
    print(*arr)
