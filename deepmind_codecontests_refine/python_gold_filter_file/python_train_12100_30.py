t = int(input())
while t:
    x,y,a,b = map(int,input().split())
    dis = y-x
    ti = dis//(a+b)
    if dis == ti*(a+b):
        print(int(ti))
    else:
        print(-1)

    t-=1