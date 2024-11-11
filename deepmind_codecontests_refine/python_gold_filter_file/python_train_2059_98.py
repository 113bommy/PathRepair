A,V = map(int, input().split())
B,W = map(int, input().split())
T = int(input())

if abs(A-B) <= V*T-W*T:
  print('YES')
else:
  print('NO')