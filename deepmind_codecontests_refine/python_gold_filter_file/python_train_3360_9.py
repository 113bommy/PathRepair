for _ in range(int(input())):
    n,x = map(int,input().split())
    a = list(map(int, input().split()))
    if len(list(set(a)))==1 and a[0]==x: print(0)
    elif sum(a) == n*x: print(1)
    elif a.count(x)>=1: print(1)
    else: print(2)