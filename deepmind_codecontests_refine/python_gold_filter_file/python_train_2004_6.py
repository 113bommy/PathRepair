for _ in range(int(input())):
    n,m,a,b=map(int,input().split())
    if n*a!=b*m: print('NO')
    else:
        print('YES')
        z=m-a
        st='1'*a+'0'*z
        st*=2
        for i in range(n):
            print(st[(a*i)%m:m+(a*i)%m])
