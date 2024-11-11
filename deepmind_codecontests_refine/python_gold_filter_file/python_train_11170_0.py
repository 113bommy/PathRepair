for _ in range(int(input())):
    n = int(input())
    lis = list(map(int,input().split()))
    lis.sort(reverse=True)
    g=0
    for i in range(n):
        if i%2==0:
            if lis[i]%2 ==0:
                g+=lis[i]
        else:
            if lis[i]%2 != 0:
                g-=lis[i]
    if g > 0:
        print('Alice')
    elif g < 0:
        print('Bob')
    else:
        print('Tie')