t = int(input())
for _ in range(t):
    n = int(input())
    a = []
    for i in range(n):
        a.append(list(input()))

    #print(a)

    if ((a[0][1] == a[1][0]) and (a[n-1][n-2] == a[n-2][n-1])):
        if (a[0][1] == a[n-1][n-2]):
            print(2)
            print("{} {}".format(n,n-1))
            print("{} {}".format(n-1,n))
        else:
            print(0)
    elif ((a[0][1] == a[1][0]) and (a[n-1][n-2] != a[n-2][n-1])):
        if (a[0][1] == a[n-1][n-2]):
            print(1)
            print("{} {}".format(n,n-1))
        else:
            print(1)
            print("{} {}".format(n-1,n))
    
    elif ((a[0][1] != a[1][0]) and (a[n-1][n-2] == a[n-2][n-1])):
        if (a[0][1] == a[n-1][n-2]):
            print(1)
            print("{} {}".format(1,2))
        else:
            print(1)
            print("{} {}".format(2,1))


    elif ((a[0][1] != a[1][0]) and (a[n-1][n-2] != a[n-2][n-1])):
        if (a[0][1] != '0'):
            print(2)
            print("{} {}".format(1,2))
        else:
            print(2)
            print("{} {}".format(2,1))

        if (a[n-1][n-2] == '0'):
            #print(1)
            print("{} {}".format(n,n-1))
        else:
            #print(1)
            print("{} {}".format(n-1,n))