A,B,C,X,Y=map(int,input().split())
Xo=A*X+B*Y
if X>=Y:
 X1=A*(X-Y)+2*C*Y
else:
 X1=B*(Y-X)+2*C*X
X2=2*C*max(X,Y)
print(min(Xo,X1,X2))