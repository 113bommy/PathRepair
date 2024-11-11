*a,d=map(int,input().split())
a = sorted(a)
print(max(0,d-(a[1]-a[0]))+max(0,d-(a[2]-a[1])))