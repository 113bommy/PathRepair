for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    if len(set(l))==1:
        print(n)
    else:
        print(1)