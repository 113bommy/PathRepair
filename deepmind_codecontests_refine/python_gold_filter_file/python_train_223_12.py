for _ in range(int(input())):
    a,b,c=map(int,input().split())
    if(c%3==0):
        print(a)
    elif(c%3==1):
        print(b)
    elif(c%3==2):
        print(a^b)