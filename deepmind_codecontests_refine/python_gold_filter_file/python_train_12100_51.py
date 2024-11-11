# cook your dish here
t = int(input())
for _ in range(t):
    x,y,a,b = list(map(int,input().split()))
    result = (y-x)/(a+b)
    if (y-x)% (a+b)==0:
        print(int(result))
    else:
        print(-1)