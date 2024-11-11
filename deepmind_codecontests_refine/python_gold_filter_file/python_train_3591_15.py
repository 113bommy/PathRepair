n,m = map(int,input().split())
if m-1 >= n-m:
    print(max(m-1,1))
else:
    print(min(m+1,n))