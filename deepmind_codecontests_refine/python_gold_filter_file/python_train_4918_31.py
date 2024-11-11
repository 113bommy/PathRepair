for _ in range(int(input())):
    a,b,c = map(int,input().split())
    x = ""
    y = "abcdefghijklmnopqrstuvwxyz"
    while(len(x)<a):
        x+=y[0:c]
        x+="a"*(b-c)
    print(x[0:a])