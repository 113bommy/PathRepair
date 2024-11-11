A,V=map(int,input().split())
B,W=map(int,input().split())
T=int(input())
v=V-W
l=abs(A-B)
if l<=v*T:
  print("YES")
else:
  print("NO")
