n=int(input())
a=list(map(int,input().split()))
l=n//2
for i in range(l):
    if i%2==0:
        a[i],a[n-1-i]=a[n-1-i],a[i]
print(*a)
        