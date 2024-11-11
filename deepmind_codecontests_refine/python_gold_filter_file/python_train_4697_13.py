a=list(map(int,input().split()))
a.sort()
print(max((a[2]-(a[1]+a[0])+1),0))