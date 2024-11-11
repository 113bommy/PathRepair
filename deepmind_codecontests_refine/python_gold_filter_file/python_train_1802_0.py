for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))

    if len(set(a))==1:
        print('0')
    else:
        k= min(a)
        cnt= a.count(k)
        print(n-cnt)