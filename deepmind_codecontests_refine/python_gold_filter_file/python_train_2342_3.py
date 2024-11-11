n=int(input())
a=[int(s) for s in input().split()]
for i in range(n):
    if i==0:
        print(a[1]-a[0],a[-1]-a[0])
    elif i==n-1:
        print(a[i]-a[i-1], a[i]-a[0])
    else:
        print(min(a[i]-a[i-1],a[i+1]-a[i]),max(a[i]-a[0],a[-1]-a[i]))