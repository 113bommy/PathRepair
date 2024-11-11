for _ in range (int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    if len(set(a))==1:
        print(n)
    else:
        print("1")