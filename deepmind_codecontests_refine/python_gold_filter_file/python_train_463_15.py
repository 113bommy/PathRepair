def up(a,b):
    if a/b == int(a/b):
        return a/b
    return int(a/b)+1

r,x,y,x1,y1=map(int, input().split())
dis = ((x1-x)**2+(y1-y)**2)**.5
print(int(up(dis,2*r)))