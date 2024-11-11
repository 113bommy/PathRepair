x,y=map(int,input().split())
n=int(input())

if n%6==1:
    print(x%(10**9+7))
elif n%6==2:
    print(y%(10**9+7))
elif n%6==3:
    print((y-x)%(10**9+7))
elif n%6==4:
    print(-x%(10**9+7))
elif n%6==5:
    print(-y%(10**9+7))
else:
    print((x-y)%(10**9+7))
