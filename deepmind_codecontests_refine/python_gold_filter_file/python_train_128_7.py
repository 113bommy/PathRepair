for _ in range(int(input())):
    n,m=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    count=0
    for i in range(len(a)):
        for j in range(len(b)):
            if a[i]==b[j]:
                count=1
                c=a[i]
                break
    if count==1:
        print("YES")
        print("1",c)
    else:
        print("NO")
