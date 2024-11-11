N = input()
A = list(map(int, input().split()))
s = sum(A)
if s%2==0:
  print("YES")
else:
  print("NO")