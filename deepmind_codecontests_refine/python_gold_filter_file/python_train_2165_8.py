n = int(input())
a = list(map(int,input().split()))
h = 0
for i in range(0,n):
  if a[i] != i-h+1:
    h += 1
if h == n:
  print(-1)
else:
  print(h)