t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int,input().split()))[::-1]
    ans = 0
    temp = arr[0]
    # print(temp)
    for i in arr:
        # print(i)
        if i > temp:
            ans += 1
        else:
            temp = i
    print(ans)

