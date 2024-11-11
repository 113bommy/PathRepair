import sys
n=int(input())
a=list(input())
A=[]
for i in range(n):
  a[i]=int(a[i])-1
  A.append(a[i]%2)

xorct=0
for i in range(n):
  if n-1==(i|n-1-i):
    xorct^=A[i]
if xorct==1:
  print(1)
  sys.exit()

if 1 in a:
  print(0)
  sys.exit()

for i in range(n):
  a[i]=a[i]//2
xorct=0
for i in range(n):
  if n-1==(i|n-1-i):
    xorct^=a[i]
if xorct==1:
  print(2)
  sys.exit()

print(0)