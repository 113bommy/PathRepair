n = int(input())
x = []
z = 0
y = 0
for i in range(0, n):
  a, b = map(int, input().split())
  x.append(a)
  x.append(b)

for i in range(0, n*2,2):
  
  if x[i]>0:
    z+=1
  if x[i]<0:
    y+=1
if z>=n-1 or y >= n-1:
  print("Yes")
else:
  print("No")
