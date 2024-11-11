for j in range(int(input())):
    n,m=map(int,input().split())
    vals=list(map(int,input().split()))
    if sum(vals)==m:
        print("YES")
    else:
        print("NO")