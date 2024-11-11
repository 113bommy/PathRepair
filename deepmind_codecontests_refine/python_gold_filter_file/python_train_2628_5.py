t = int(input())
while t>0:
    t-=1
    n,m = map(int,input().split())
    if n==1 or m == 1 or (n==2 and m ==2):
        print("YES")
    else:
        print("NO")