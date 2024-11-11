x=list(map(int,input().split()))
x.sort()
print(max(0,x[2]-x[1]-x[0]+1))
