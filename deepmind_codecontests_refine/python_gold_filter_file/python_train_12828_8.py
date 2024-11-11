n=int(input())
for i in range(n):
    li=list(map(int,input().split()))
    t=li[0]
    x=li[1]
    y=li[2]
    minplace=max(1,min(x+y-t+1,t))
    maxplace=min(x+y-1,t)
    print(minplace,end=" ")
    print(maxplace)