for _ in [0]*int(input()):
    a,b = map(int,input().split())
    print(min([a,b,(a+b)//3]))