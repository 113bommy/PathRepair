n0,n1,n2,n3=map(int,input().split())
if n2+n3==0:
    if n0==n1:
        print("YES")
        for i in range(n0):
            print(0,1,end=" ")
    elif abs(n0-n1)==1:
        print("YES")
        
        if n0<n1:
            print(1,end=" ")
            for i in range(n0):
                print(0,1,end=" ")
        else:
            print(0,end=" ")
            for i in range(n1):
                print(1,0,end=" ")
    else:
        print("NO")
            
elif n0+n1==0:
    if n2==n3:
        print("YES")
        for i in range(n2):
            print(2,3,end=" ")
    elif abs(n2-n3)==1:
        print("YES")
        
        if n2<n3:
            print(3,end=" ")
            for i in range(n2):
                print(2,3,end=" ")
        else:
            print(2,end=" ")
            for i in range(n3):
                print(3,2,end=" ")
    else:
        print("NO")
elif n0+n3==0:
    if n1==n2:
        print("YES")
        for i in range(n1):
            print(2,1,end=" ")
    elif abs(n2-n1)==1:
        print("YES")
        
        if n2<n1:
            print(1,end=" ")
            for i in range(n2):
                print(2,1,end=" ")
        else:
            print(2,end=" ")
            for i in range(n1):
                print(1,2,end=" ")
    else:
        print("NO")
elif n0<=n1 and n3<=n2 and (n1-n0==n2-n3):
    print("YES")
    for j in range(n0):
        print(0,1,end=" ")
    for k in range(n1-n0):
        print(2,1,end=" ")
    for l in range(n3):
        print(2,3,end=' ')
elif n0<=n1 and n3<=n2 and (n1-n0==n2-n3+1):
    print("YES")
    print(1,end=" ")
    for j in range(n0):
        print(0,1,end=" ")
    for k in range(n2-n3):
        print(2,1,end=" ")
    for l in range(n3):
        print(2,3,end=' ')
elif n0<=n1 and n3<=n2 and (n1-n0+1==n2-n3):
    print("YES")
    for j in range(n0):
        print(0,1,end=" ")
    for k in range(n1-n0):
        print(2,1,end=" ")
    for l in range(n3):
        print(2,3,end=' ')
    print(2)
else:
    print("NO")


























            