n=list(map(int, input().split()))
p=0
for i in range(n[0]):
    if (i+1)%2!=0:
       for j in range(n[1]):
           print("#", end="")
    if (i+1)%2==0:
        if p == 1:
            print("#", end="")
        for j in range(n[1]-1):
            print(".", end="")
        if p==0:
            print("#", end="")
        p=(p+1)%2
    print("")