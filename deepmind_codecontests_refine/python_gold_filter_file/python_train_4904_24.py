n = int(input())
if n < 3 : 
    print("No")
else :
    tot = n * (n+1) / 2
    for i in range(2, n+1) :
        if tot % i == 0 :
            print("Yes")
            print("1 %d" % i)
            print(str(n-1), end='')
            for j in range(1, n+1) :
                if (j == i) : continue
                print(" %d" % j, end='')
            exit()
