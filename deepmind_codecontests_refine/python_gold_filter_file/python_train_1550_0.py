f=0
while 1:
    try:n=int(input())
    except:break
    if f:print()
    f=1
    a=[[0 for _ in range(5)]for _ in range(8)]
    for i in range(4,-1,-1):
        b=n%10
        a[not b//5][i]=1
        a[b%5+3][i]=1
        n//=10
    for i in range(8):
        for j in range(5):
            if i==2:print('=',end='')
            else:print(' ' if a[i][j] else '*',end='')
        print()