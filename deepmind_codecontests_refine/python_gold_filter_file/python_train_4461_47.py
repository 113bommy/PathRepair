a=list(map(int,input().split()))
a.sort()
print(a[0] if a[0]!=a[1] else a[2])
