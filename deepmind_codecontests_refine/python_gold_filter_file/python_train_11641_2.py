n = int(input())
a = list(map(int,input().split()))
b = []
for i in range(n):
  if a[i] > i+1:
    print(-1)
    exit()
  else:
    b.insert(a[i]-1,a[i])
for i in range(n):
  print(b[i])
