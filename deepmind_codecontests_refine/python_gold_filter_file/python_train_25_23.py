for _ in range(int(input())):
    n = int(input())
    arr = []
    for i in range(n):
        arr.append([ch for ch in input()])
    count = 0
    changes = []
    if arr[0][1] == arr[1][0]:
        if arr[n-1][n-2] == arr[1][0]:
            count+=1
            changes.append("{} {}".format(n, n-1))
        if arr[n-2][n-1] == arr[1][0]:
            count+=1
            changes.append("{} {}".format(n-1, n))
    elif arr[0][1] != arr[1][0]:
        if arr[n-1][n-2] == arr[n-2][n-1]:
            if arr[1][0] == arr[n-1][n-2]:
                count += 1
                changes.append("{} {}".format(2,1))
            if arr[0][1] == arr[n-1][n-2]:
                count += 1
                changes.append("{} {}".format(1,2))
        else:
            count += 1
            changes.append("{} {}".format(1,2))
            if arr[n-1][n-2] == arr[1][0]:
                count += 1
                changes.append("{} {}".format(n,n-1))
            if arr[n-2][n-1] == arr[1][0]:
                count += 1
                changes.append("{} {}".format(n-1, n))
    print(count)
    # if count == 0:
    #     break
    print("\n".join(changes))
        