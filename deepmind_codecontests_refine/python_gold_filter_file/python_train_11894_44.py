t = int(input())
for we in range(t):
    n = int(input())
    l=[1]
    if n<=3:
        print(-1)
    elif n==4:
        print("2 4 1 3")
    elif n==6:
        print("1 3 5 2 6 4")
    elif n==5:
        print("1 3 5 2 4")
    elif n>4:
        if n%2==0:
            k=1
            while k<n-2:
                k+=2
                l.append(k)
            k-=3
            l.append(k)
            k+=4
            l.append(k)
            k-=2
            l.append(k)
            k-=4
            l.append(k)
            while k>3:
                k-=2
                l.append(k)
        else:
            k = 1
            while k<n-1:
                k+=2
                l.append(k)
            k-=3
            l.append(k)
            k+=2
            l.append(k)
            k-=4
            l.append(k)
            while(k>3):
                k-=2
                l.append(k)
        for i in l:
            print(i, end=" ")
                       