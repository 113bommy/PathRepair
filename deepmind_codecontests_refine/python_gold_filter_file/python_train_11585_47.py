import math
t=int(input())
for _ in range (t):
    a,b=map(int,input().split())
    if(b==a):
        print("0")
    elif(b>a):
        if(a%2==b%2):
            print("2")
        else:
            print("1")
    else:
        if(a%2==b%2):
            print("1")
        else:
            print("2")