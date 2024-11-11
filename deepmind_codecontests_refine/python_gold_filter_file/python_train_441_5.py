for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    c=list(map(int,input().split()))
    p=[]
    for i in range(n):
        x=[a[i],b[i],c[i]]
        if i==0:
           p.append(x[0])
           print(x[0],end=" ")
        elif i==n-1:
            if x[1] != p[i - 1] and p[0]!=x[1]:
                p.append(x[1])
                print(x[1], end=" ")
            elif x[2] != p[i - 1] and p[0]!=x[2]:
                p.append(x[2])
                print(x[2], end=" ")
            else:
                p.append(x[0])
                print(x[0], end=" ")
        else:
           if x[1]!=p[i-1]:
              p.append(x[1])
              print(x[1],end=" ")
           elif x[2]!=p[i-1]:
               p.append(x[2])
               print(x[2],end=" ")
           else:
               p.append(x[0])
               print(x[0],end=" ")
    print()