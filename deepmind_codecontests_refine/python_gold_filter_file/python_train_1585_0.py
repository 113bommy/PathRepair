t = int(input())

for _ in range(t):
    n = int(input())
    num = int(input())
    str_num = str(num)
    lis = [-1]*n
    lis[0] = int(str_num[0])
    for j in range(1,n):
        lis[j] = lis[j-1]+int(str_num[j])
    f = 0
    pos = -1
    for i in range(n-1,-1,-1):
        if int(str_num[i]) != 0:
            pos = i
            break

    for j in range(pos,-1,-1):
        if lis[j]%2 == 0 and int(str_num[j])%2 != 0:
            pos = j
            f = 1
            break    

    if f == 0:
        print(-1,end="")
    else:
        for j in range(pos+1):
            print(str_num[j],end="")

    print()        

            
                