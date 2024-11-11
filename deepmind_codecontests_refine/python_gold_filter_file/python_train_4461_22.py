a=list(map(int,input().split()))
a.sort()
print(a[0] if a[1]==a[2] else a[2])