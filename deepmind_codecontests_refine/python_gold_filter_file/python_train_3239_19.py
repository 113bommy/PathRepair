from bisect import bisect_left
n,m = map(int,input().split())
if m==0:
    print(n,n)
elif n==1:
    print(1,1)
    
else:    
    mn=max((n-(m*2)),0)
    value = [int((n*(n-1))/2) for n in range(2,n+5)]
    mx = bisect_left(value,m)
    mxm=max(n-mx-2,0)

    print(mn,mxm)
