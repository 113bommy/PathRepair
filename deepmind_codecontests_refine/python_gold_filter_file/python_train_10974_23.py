n=int(input())
if n%2:
    print(n*n//2+1)
    for i in range(n*n):
        if i%2:
            print(".",end="")
        else:
            print("C",end="")
        if (i+1)%n==0:
            print("")
else:
    print(n*n//2)
    for i in range(n):
        for j in range(n):
            if i%2!=j%2:
                print(".",end="")
            else:
                print("C",end="")
        print("")