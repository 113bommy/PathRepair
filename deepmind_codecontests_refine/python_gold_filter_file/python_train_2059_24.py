A, V = map(int,input().split())
B, W = map(int,input().split())
T    = int(input())

if (V-W)*T >= abs(A-B):
  print("YES")
else:
  print("NO")
#
