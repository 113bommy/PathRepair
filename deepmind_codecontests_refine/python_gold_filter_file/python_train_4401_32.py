for u in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    s=list(set(l))
    if(len(s)==1):
        print(n)
    else:
        print(1)
