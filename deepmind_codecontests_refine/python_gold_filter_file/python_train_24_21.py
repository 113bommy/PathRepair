t=int(input())
for o in range(0,t):
    n = int(input())
    arr = list(map(int,input().split(" ")))
    sum = arr[0] + arr[1]
    flag = 0
    for i in range(2,n):
        if(arr[i] >= sum):
            print("{} {} {}".format(1, 2, i + 1))
            flag = 1
            break
    if(flag == 0):
        print("-1")