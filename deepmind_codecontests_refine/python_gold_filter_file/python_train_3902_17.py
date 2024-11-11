a=[int(x) for x in input().split()]
n=a[0]
m=a[1]
for i in range(1,n+1):
    if i%2!=0:
        for j in range(m-1):
            print("#",end="")
        print("#")
    elif i%4==2:
        for j in range(m-1):
            print(".",end="")
        print("#")
    else:
        print("#",end="")
        for j in range(m-2):
            print(".",end="")
        print(".")
