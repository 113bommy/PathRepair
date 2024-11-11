for _ in range(int(input())):
    n=int(input())
    l=[int(i) for i in input().split(' ',n-1)]
    s=0
    x=0
    for i in range(len(l)):
        s+=l[i]
        x=x^l[i]
    print(2)
    print(x,s+x)