for t in range(int(input())):
    n,x, k = map(int, input().split())

    v = k//x
    
    if(n>=v):
        c = (v)*(n-v) + (v)*(v -1)//2
    else:
        c = n*(n-1)//2
    print(c)