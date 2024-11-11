n,m = [int(x) for x in input().split()]
for i in range(1,n+1):
    if i%2 == 1:
        s = ['#']*m
        print(''.join(s))
    elif i%4 == 0:
        a = ['#']+['.']*(m-1)
        print(''.join(a))
    else:
        b = ['.']*(m-1)+['#']
        print(''.join(b))