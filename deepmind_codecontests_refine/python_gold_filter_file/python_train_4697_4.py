c=list(map(int,input().split()))
c.sort()
print(max(0,c[2]-(c[0]+c[1]-1)))