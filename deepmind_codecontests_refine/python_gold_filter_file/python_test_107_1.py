problem_num = int(input())
for i in range(problem_num):
    arr = list(map(int,input().split()))
    if abs(arr[1]-arr[2])>=2 or arr[1] + arr[2] > arr[0] - 2:
        print(-1)
        continue

    init = 0
    lst = [init]
    if arr[1]>arr[2]:
        for j in range(arr[1]):
            lst.append(init + j + 1)
            lst.append(init - j - 1)
        for j in range(arr[0]-arr[1]-arr[2]-2):
            lst.append(init-j-arr[1]-1)
    if arr[1]<arr[2]:
        for j in range(arr[2]):
            lst.append(init - j - 1)
            lst.append(init + j + 1)
        for j in range(arr[0]-arr[1]-arr[2]-2):
            lst.append(init+j+arr[2]+1)
    if arr[1]==arr[2]:
        for j in range(arr[2]):
            lst.append(init + j + 1)
            lst.append(init - j - 1)
        for j in range(arr[0]-arr[1]-arr[2]-1):
            lst.append(init+j+arr[2]+1)
    min_val = min(lst)
    lst = [str(i-min_val+1) for i in lst]
    print(' '.join(lst))
