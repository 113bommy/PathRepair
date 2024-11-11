for x in range(int(input())):
    n = int(input())
    m=list(map(int,input().split()))
    if len(set(m))==1:
        print(n)
    else:
        print(1)