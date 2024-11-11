numx,numy,numz,k=list(map(int,input().split()))
X=list(map(int,input().split()))
Y=list(map(int,input().split()))
Z=list(map(int,input().split()))

XY=[ x + y for x in X for y in Y]
XY.sort(reverse=True)
XY=XY[:k]
XYZ=[xy + z for xy in XY for z in Z]
XYZ.sort(reverse=True)

for i in range(k):
  print(XYZ[i])