for _ in range(int(input())):
    m=int(input())
    a=list(map(int,input().split()))
    if len(set(a))==1:
        print(m)
    else:
        print("1")