A,B,C=map(int,input().split())
if A<C:
  B=B-(C-A)
  A=0
else:
  A=A-C
print(A,max(B,0))