n,k=list(map(int,input().split()))
a=list(map(int,input().split()))
if k>n:
    print(-1)
else:
    a.sort(reverse=True)
    print(a[k-1],0)
    