a,b = map(int,input().split())
c = list(map(int,input().split()))
c.sort()
print(sum(c[0:b]))