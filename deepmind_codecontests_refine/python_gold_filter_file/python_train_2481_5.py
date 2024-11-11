N=int(input())
D,X=map(int,input().split())
for i in range(N):
  a=int(input())
  X+=(D-1+a)//a
print(X)