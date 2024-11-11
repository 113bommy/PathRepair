t = int(input())
for i in range(t):
    n = int(input())
    if(n<4):
        print(-1)
        continue
    for j in range(n+1):
        if((n-j)%2!=0):
            print(n-j,end=" ")
    print(4,end = " ")
    print(2,end=" ")
    if(n>=6):
        for j in range(6,n+1):
            if(j%2==0):
                print(j,end = " ")
    print(" ")
    