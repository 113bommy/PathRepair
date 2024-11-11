for _ in range(int(input())):
    n,m=map(int,input().split())
    if m%2==1:
        for v in range(n):
            a,b=map(int,input().split())
            c,d=map(int,input().split())
        print('NO')
        continue
    flag=0    
    for v in range(n):
        a,b=map(int,input().split())
        c,d=map(int,input().split())
        if c==b:
            flag=1
    if flag==1:
        print('YES')
        continue
    print('NO')             
    