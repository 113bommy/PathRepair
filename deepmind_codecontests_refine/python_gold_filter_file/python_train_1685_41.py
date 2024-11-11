t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split(" ")))
    lowest = a[::-1][0]
    count = 0
    days = []
    for j in a[::-1]:
        if j <= lowest:
            lowest = j
        else:
            count += 1
    print(count)
