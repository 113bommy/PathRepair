for i in range(int(input())):
    q=int(input())
    w=list(map(int,input().split()))
    e=max(w)
    k=1
    for i in w:
        if i%2!=e%2:
            print('NO')
            k=0
            break
    if k==1:
        print('YES')
        