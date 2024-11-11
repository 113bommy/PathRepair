for t in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    p=min(l)
    if(l[0]>l[-1]):
        print('NO')
    else:
        print('YES')