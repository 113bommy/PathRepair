for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    o=l[0]%2
    flag=0
    for i in l:
        if i%2!=o:
            flag=1
            break
    if flag==1:
        print('NO')
    else:
        print('YES')
            