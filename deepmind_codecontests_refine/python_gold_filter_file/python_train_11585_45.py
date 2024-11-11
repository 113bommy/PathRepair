for each in range(int(input())):
    a,b=map(int,input().split())
    print(abs(b-a)//10+(1 if abs(b-a)%10!=0 else 0))