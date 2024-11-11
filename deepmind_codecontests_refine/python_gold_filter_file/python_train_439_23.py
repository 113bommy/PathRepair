for t in range (int(input())):
    a,b=map(int,input().split())
    print(min(a,b,int((a+b)/3)))