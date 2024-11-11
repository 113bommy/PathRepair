n=int(input())

t=list(map(int,input().split()))


if n==1:
    if t[0]==0:
        print('NO')
    else:
        print('YES')
else:
    if t.count(0)==1:
        print('YES')
    else:
        print('NO')
