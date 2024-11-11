t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    x=set(a)
    y=len(x)
    if y==n:
        print("NO")
    else:
        print("YES")