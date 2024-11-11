for _ in range(int(input())):
    input()
    flag = 0
    A  = list(map(int , input().split()))
    B  = list(map(int , input().split()))
    for i in A:
        if B.count(i)  > 0:
            print('YES')
            print(1 , i)
            flag = 1
            break
    if flag == 0: print('NO')
