for _ in range(int(input())):
    n=int(input())
    l=[int(x) for x in input().split()]
    p=set(l)
    if len(p)==1:
        print(n)
    else:
        print(1)