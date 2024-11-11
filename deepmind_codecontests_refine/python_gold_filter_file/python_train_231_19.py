T=int(input())
for t in range(T):
    n=int(input())
    z=0
    while(n>1):
        if(n%6==0):
            n=n//6
            z=z+1
        elif(n%2!=0):
            n=n*2
            z=z+1
        else:
            n=0
            z=-1
    print(z)