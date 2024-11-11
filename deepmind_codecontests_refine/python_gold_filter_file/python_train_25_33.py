
t=int(input())
for _ in range(t):
    n = int(input())
    l=[]
    i=int(0)
    for i in range(n):
        l.append(input())

    x1=l[0][1]
    x2=l[1][0]
    y1,y2 = l[-2][-1],l[-1][-2]
    # print(x1)
    # print(x2)
    # print(y1)
    # print(y2)
    if((x1==x2)and(x2==y1)and(y1==y2)):
        print("2")
        print("1 2")
        print("2 1")
        # print("k")
    elif ((x1==x2)and(y1==y2)):
        print("0")
    elif ((x1==x2) and (y1!=y2)):
        if ((x1=='0') and (y1=='0')):
            print("1")
            print(n-1,n)
        elif ((x1=='0') and (y2=='0')):
            print("1")
            print(n, n-1)
        elif ((x1=='1') and (y1=='1')):
            print("1")
            print(n-1, n)
        elif ((x1=='1') and (y2=='1')):
            print("1")
            print(n, n-1)
    elif ((x1!=x2) and (y1==y2)):
        if ((y1=='0') and (x1=='0')):
            print("1")
            print("1 2")
        elif ((y1=='0') and (x2=='0')):
            print("1")
            print("2 1")
        elif ((y1=='1') and (x1=='1')):
            print("1")
            print("1 2")
        elif ((y1=='1') and (x2=='1')):
            print("1")
            print("2 1")
    elif ((x1!=x2) and (y1!=y2)):
        if (x1=='1' and y1=='1'):
            print("2")
            print("2 1")
            print(n-1,n)
        elif (x1=='1' and y2=='1'):
            print("2")
            print("2 1")
            print(n, n-1)
        elif (x1=='0' and y1=='0'):
            print("2")
            print("2 1")
            print(n-1, n)
        elif (x1=='0' and y2=='0'):
            print("2")
            print("2 1")
            print(n,n-1)
