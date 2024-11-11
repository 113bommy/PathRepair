n,s = map(int,input().split())
if s < 2*n:
    print('NO')
else:
    print('yes')
    print(*([1]*(n-1) + [s-(n-1)] ))
    print(n)
