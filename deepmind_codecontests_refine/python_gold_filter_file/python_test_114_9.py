for i in range(int(input())):
    n=int(input())
    a=[int(j) for j in input().split()]
    pair=n//2
    p=min(a)
    for j in a:
        if j!=p and pair:
            print(j,p)
            pair-=1
        if pair==0:
            break