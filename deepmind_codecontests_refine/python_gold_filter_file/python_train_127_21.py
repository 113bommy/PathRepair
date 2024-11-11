for t in range(int(input())):
    n,m = map(int,input().split())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    arr = 0
    flag = 0
    for i in a:
        if i in b:
            arr = i;
            print("YES")
            print(1,arr)
            flag = 1
            break
    if flag == 0:
        print("NO")