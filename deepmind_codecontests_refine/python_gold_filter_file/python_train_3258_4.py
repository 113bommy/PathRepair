for _ in range(int(input())):
    n,m=map(int,input().split())
    gc=0
    cost=0
    k=[int(i) for i in input().split()]
    c=[int(i) for i in input().split()]
    k=sorted(k)[::-1]
    for i in k:
        if(c[gc]<c[i-1] and gc<=i-1):
            cost+=c[gc]
            gc+=1
        else:
            cost+=c[i-1]
        # print(cost)
    print(cost)
