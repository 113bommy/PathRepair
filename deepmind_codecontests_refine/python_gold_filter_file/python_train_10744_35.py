for i in range (int(input())):
    r,b,k=map(int,input().split())
    if (r-1>b+k or b-1>r+k or k-1>r+b):
        print ("No")
    else:
        print("yes")