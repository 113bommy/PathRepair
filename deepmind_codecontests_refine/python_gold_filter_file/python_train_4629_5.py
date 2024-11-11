n = int(input())

if n < 4: print("NO")
else:
    print("YES")
    if n % 2 == 0:
        for i in range(5,n,2):
            print("%s - %s = 1\n1 * 1 = 1"%(str(i+1),str(i)))
        print("1 * 2 = 2")
    else:
        for i in range(6,n,2):
            print("%s - %s = 1\n1 * 1 = 1"%(str(i+1),str(i)))
        print("5 - 2 = 3\n3 - 1 = 2")
    print("2 * 3 = 6\n6 * 4 = 24")
