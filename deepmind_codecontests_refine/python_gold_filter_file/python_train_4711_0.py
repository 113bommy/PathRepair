R = lambda: map(int, input().split())
for _ in range(int(input())):
    input()
    arr = sorted(R())
    diff, pre = arr[1] - arr[0], arr[1]
    for i in arr[2:]:
        diff = min(diff, i - pre)
        pre = i
    print(diff)
