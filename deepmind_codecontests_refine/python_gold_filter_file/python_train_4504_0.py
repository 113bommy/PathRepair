for i in range(int(input())):
    n,m=map(int,input().split())
    l=[]
    c=0
    for j in range(n):
        a=list(map(int,input().split()))
        l.append(a)
    for j in range(n):
        for k in range(m):
            if j==0 and k==0 or j==n-1 and k==0 or j==0 and k==m-1 or j==n-1 and k==m-1:
                if l[j][k]>2:
                    c=1
                    break
                else:
                    l[j][k]=2
            elif j==0 or k==0 or j==n-1 or k==m-1:
                if l[j][k]>3:
                    c=1
                    break
                else:
                    l[j][k]=3
            else:
                if l[j][k]>4:
                    c=1
                    break
                else:
                    l[j][k]=4
        if c==1:
            break
    if c==1:
        print("NO")
    else:
        print("YES")
        for j in range(n):
            for k in range(m):
                print(l[j][k],end=" ")
            print()