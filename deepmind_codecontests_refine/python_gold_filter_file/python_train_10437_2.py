for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    for i in range(n):
        if i%2==0:
            if l[i]<0:
                l[i]=l[i]*(-1)
        else:
            if l[i]>0:
                l[i]=l[i]*(-1)
    print(*l)
    