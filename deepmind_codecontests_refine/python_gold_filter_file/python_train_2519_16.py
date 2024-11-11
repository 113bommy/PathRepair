for _ in range(int(input())):
    a,b,n,s=map(int,input().split())
    if s%n<=b and a*n+b>=s:
        print("yes")
    else:
        print("no")