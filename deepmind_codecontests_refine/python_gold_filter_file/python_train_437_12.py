for b in range(int(input())):
    n=int(input())
    g=i=0
    x=sorted([int(j) for j in input().split()])
    while (n-1)>i :
        if x[i]==x[i+1]:
            
            i+=1
        else:
            g+=1
            i+=1
    g+=1
    print(g)
    