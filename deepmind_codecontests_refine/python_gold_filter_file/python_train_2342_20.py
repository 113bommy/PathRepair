n=int(input())
a=list(map(int,input().split()))
d=abs
for i in range(n):
    g=g1=9999999999
    if n-i-1>0:
        g=a[i+1]
    if i>0:
        g1=a[i-1]
    print(min(d(a[i]-g),d(a[i]-g1)),max(d(a[i]-a[0]),d(a[i]-a[n-1])))