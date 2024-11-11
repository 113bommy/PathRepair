for ttt in range(int(input())):
    a,b=map(int,input().split())
    if a==b:
        print(0)
    elif(a<b):
        if a%2!=b%2:
            print(1)
        elif a%2==0 and b%2==0:
            print(2)
        elif(a%2!=0 and b%2!=0):
            print(2)
    else:
        if(a%2!=0 and b%2!=0):
            print(1)
        elif a%2!=b%2:
            print(2)
        elif a%2==0 and b%2==0:
            print(1)