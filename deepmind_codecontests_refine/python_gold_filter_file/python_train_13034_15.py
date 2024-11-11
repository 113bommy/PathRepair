for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    s=0
    for i in a:
        s^=i
    print(2)
    print(s,s+sum(a))