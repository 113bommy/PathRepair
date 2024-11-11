for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    s = 0
    f=0
    for i in l:
        s+=i
        if s<=0:
            f=1
            break
    s=0
    for i in l[::-1]:
        s+=i
        if s<=0:
            f=1
            break
    if f==1:
        print('NO')
    else:
        print('YES')