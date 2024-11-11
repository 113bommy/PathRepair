n=int(input())
for i in range(n):
    x=list(map(int,input().split()))
    x.sort()
    a=x[0]
    b=x[1]
    c=x[2]
    if a*a+b*b==c*c:
        print('YES')
    else:
        print('NO')
