n=int(input())
for i in range(n):
    p=list(map(int,input().split()))
    p.sort()
    a=p[0]
    b=p[1]
    c=p[2]
    if a*a+b*b==c*c:
        print('YES')
    else:
        print('NO')
