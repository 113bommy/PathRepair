a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = 1
d = 0
for i in b:
  d += i
  if d <= a[1]:
    c += 1
print(c)
