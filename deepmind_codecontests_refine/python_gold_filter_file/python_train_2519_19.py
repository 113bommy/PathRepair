def mai(a):
    for i in range(a):
        a,b,n,s=map(int,input().split())
        if s%n<=b and a*n+b>=s:
            print('YES')
        else:
            print('NO')
            
            
        

mai(int(input()))