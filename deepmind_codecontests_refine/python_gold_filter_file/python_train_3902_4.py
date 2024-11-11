n,m=(int(a) for a in input().split())

for i in range(1,n+1):
    for j in range(m):
        if i%2==0:
            if i%4!=0:
               if j==m-1:
                    print("#", end="")
               else:
                    print(".",end="")
            elif i%4==0:
                if j==0:
                    print("#",end="")
                else:
                    print(".",end="")
        else:
            print("#", end='')
    print("")
