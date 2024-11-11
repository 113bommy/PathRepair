from math import ceil
a=int(input())
b=list(map(int, input().split()))
cnt=0
c=0
d=0
for i in b:
 
  if i<0:
    cnt+=1
  elif i>0:
    c+=1
  else:
    d+=1
if c>=ceil(len(b)/2):
  print("1")
elif cnt>=ceil(len(b)/2):
  print("-1")
else:
  print("0")
