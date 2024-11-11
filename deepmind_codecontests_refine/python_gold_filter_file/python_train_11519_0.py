n,m,k=map(int,input().split())
a=[int(x) for x in input().split()]
if n%2==0:
    print(0)
else:
    print(min( min(a[::2]), m//(n//2+1)*k))
