n=int(input())
a=list(map(int,input().split()))
a=sorted(a)
print(min(a[n-2]-a[0],a[n-1]-a[1]))
