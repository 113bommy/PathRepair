n,m=map(int,input().split())
if n-m>=m:
    print(min(n,m+1))
else:
    print(max(1,m-1))