for _ in range(int(input())):
    n=int(input())
    if n%4!=0:
        print('NO')
    else:
        print('YES')
        a=[]
        k=2
        for i in range(n//2):
            a.append(k)
            k+=4
        b=[]
        for i in range(0,n//2,2):
            b.append(a[i]-1)
            b.append(a[i+1]+1)
        a+=b
        print(*a)