from math import ceil

a,b,c=map(int,input().split())
k=int(input())

for i in range(k):
  if b<=a:b*=2
  elif c<=b:c*=2

if b>a and c>b: print('Yes')
else:print('No')