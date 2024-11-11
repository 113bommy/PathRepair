n = int(input())
arr = list(map(int, input().split()))
flag = 0
for i in range(n):
    for j in range(n):
        for k in range(n):
            if i != j and j != k:
                temp = sorted([arr[i], arr[j], arr[k]])
                if arr[k] == arr[i] + arr[j]:
                    print(k+1, j+1, i+1)
                    flag = 1
                    break
        if flag:
            break
    if flag:
        break
else:
    print(-1)
