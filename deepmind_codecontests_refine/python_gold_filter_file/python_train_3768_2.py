for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    s=sum(a)
    if s%n==0:
        print(s//n)
    else:
        print((s//n)+1)