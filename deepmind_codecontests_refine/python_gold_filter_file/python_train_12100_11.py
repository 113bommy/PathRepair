for _ in range(int(input())):
    a,b,c,d=map(int,input().strip().split())
    if((b-a)%(c+d)==0):
        print((b-a)//(c+d))
    else:
        print(-1)    