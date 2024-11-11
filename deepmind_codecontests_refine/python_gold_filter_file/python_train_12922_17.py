n=int(input())
a=list(map(int,input().split()))
a.sort()
print(min(a[-1]-a[1],a[n-2]-a[0]))
