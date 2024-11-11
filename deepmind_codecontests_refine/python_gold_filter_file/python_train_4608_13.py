t=int(input())
for _ in range(t):
    a,b,n,m=map(int,input().split())
    if m+n>a+b:
        print("No")
    elif min(a,b)>=m:
        print("Yes")
    else:
        print("No")
