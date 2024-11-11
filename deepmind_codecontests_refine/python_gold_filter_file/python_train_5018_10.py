for t in range(int(input())):
    a,b=[int(x) for x in input().split()]
    k=abs(a-b)
    res=k//5
    k%=5
    res+={0:0,1:1,2:1,3:2,4:2}[k]
    print(res)
