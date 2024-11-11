for i in range(int(input())):
    X,Y,A,B=[int(i) for i in input().split(" ")]
    if (Y-X)%(A+B)==0:
        print((Y-X)//(A+B))
    else:
        print(-1)