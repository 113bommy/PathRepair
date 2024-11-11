t=int(input())
while(t>0):
    a,b,n,m = map(int, input().split())
    if (a+b)>=(n+m) and m<=min(a,b):
        print("Yes")
    else:
        print("No")
        
    t-=1