n = int(input())
arr = [int(x) for x in input().split()]
for i in range(30,-1,-1):
    dem = 0
    for x in arr:
        if  x & (1<<i) :
            dem += 1
    if dem == 1:
        cur = 0
        for j in range(n):
            if arr[j] & (1<<i):
                cur = j
        print(arr[cur],end=' ')
        for j in range(n):
            if j != cur:
                print(arr[j],end=' ')
        exit()
for x in arr:
    print(x,end=' ')