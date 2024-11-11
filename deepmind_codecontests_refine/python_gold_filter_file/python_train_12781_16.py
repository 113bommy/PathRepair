a,b,c = map(int, input().split())
k = int(input())
t = 0
while(a>=b):
  b = 2*b
  t +=1
while(b>=c):
  c = 2*c
  t +=1
if(t<=k):
  print("Yes")
else:
  print("No")