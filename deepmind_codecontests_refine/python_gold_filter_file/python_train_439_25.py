for z in range(int(input())):
    a,b = map(int,input().split())
    print(min(a,b,(a+b)//3))