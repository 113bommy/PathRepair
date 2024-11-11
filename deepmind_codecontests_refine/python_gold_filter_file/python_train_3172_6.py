n = int(input())
X = []
Y = []
for i in range(n):
    x, y = input().split()
    X.append(int(x))
    Y.append(int(y))
maxx=max(X)
maxy=max(Y)
minx=min(X)
miny=min(Y)
x1=abs(maxx-minx)
y1=abs(maxy-miny)
print(max(x1,y1)**2)