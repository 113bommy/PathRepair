A,V=map(int,input().split())
B,W=map(int,input().split())
T=int(input())
X=abs(A-B)
Y=V-W
if X<=Y*T:
  print('YES')
else:
  print('NO')