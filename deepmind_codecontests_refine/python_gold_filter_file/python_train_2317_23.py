t=int(input())
for i in range(0,t):
    n=int(input())
    b=0
    c=0
    bb=0
    cc=0
    m=0
    l=0

    a=list(map(int,input().split()))
    for j in range(0,2*n):

        if(a[j]%2==0):

            m=m+1
    if (m % 2 == 0):
        for j in range(2 * n - 1, -1,-1):
            if (a[j]%2 == 0):
                b = b + 1
                if (b == 2):
                    l = j + 1
                    break

    b=0
    if(n==2):
        print("1",end=" ")
        print("2")
        print()

    else:
        if(m%2!=0):

            for j in range(0,2*n):
                if(a[j]%2==0):
                    b=b+1
                    if(b==1):
                        bb=j+1
                    if(b==2):
                        print(bb, end=" ")
                        print(j + 1)
                        print()
                        b=0
                else:
                    c = c + 1
                    if (c == 1):
                        cc = j + 1
                    if (c == 2):
                        print(cc,end=" ")
                        print(j+1)
                        print()
                        c= 0
        else:
            if(m==0):
                for j in range(0,2*n-2):
                    if(a[j]%2==0):
                        b=b+1
                        if(b==1):
                            bb=j+1
                        if(b==2):
                            print(bb, end=" ")
                            print(j + 1)
                            print()
                            b=0
                    else:
                        c = c + 1
                        if (c == 1):
                            cc = j + 1
                        if (c == 2):
                            print(cc,end=" ")
                            print(j+1)
                            print()
                            c= 0

            else:
                c=0
                for j in range(0,2*n):
                    if(a[j]%2==0):
                        b=b+1
                        if(b==1):
                            if ((j + 1) == l):
                                b=0
                            bb=j+1
                        if(b==2):

                            print(bb, end=" ")
                            print(j + 1)
                            print()
                            b=0
                    else:
                        c = c + 1
                        if (c == 1):
                            cc = j + 1
                        if (c == 2):
                            print(cc,end=" ")
                            print(j+1)
                            print()
                            c= 0


