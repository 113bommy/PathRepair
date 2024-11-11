n, c = map(int, input().split())
if (n == 1):
    print(1)
else:
    a = list(map(int, input().split()))
    sum = 1
    for i in range(n - 1):
        if a[i + 1] - a[i] <= c:
            sum += 1
        else :
            sum = 1
    print(sum)
