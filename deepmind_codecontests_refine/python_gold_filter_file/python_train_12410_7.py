for i in range(int(input())):
    n,p1,p2=input().split()
    l1=list(map(int,input().split()))
    l2=list(map(int,input().split()))
    if(max(l1)>max(l2)):
        print("YES")
    else:
        print("NO")
