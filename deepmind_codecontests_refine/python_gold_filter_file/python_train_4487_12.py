n=int(input())
k=1000000009
a=[int(i) for i in input().split()]
a.sort()
if n==1:
    print(0)
    exit()
else:
    for i in range(1, n):
        k=min(k, a[i+n-1]-a[i])
    print(min((a[2*n-1]-a[0])*k, (a[n-1]-a[0])*(a[2*n-1]-a[n])))