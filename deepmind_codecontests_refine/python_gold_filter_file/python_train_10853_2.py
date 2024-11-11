import math
t=int(input())
for w in range(t):
    n=int(input())
    if(n==1):
        print("FastestFinger")
    elif(n%2==1):
        print("Ashishgup")
    elif(n==2):
        print("Ashishgup")
    else:
        if(math.log2(n)==int(math.log2(n))):
            print("FastestFinger")
        elif(n%4==0):
            print("Ashishgup")
        else:
            k=n//2
            for i in range(2,int(math.sqrt(k))+1):
                if(k%i==0):
                    k=-1
                    break
            if(k==-1):
                print("Ashishgup")
            else:
                print("FastestFinger")