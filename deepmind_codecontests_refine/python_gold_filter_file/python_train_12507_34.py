import sys
n=int(input())
lr=[]
rr=[]
suma=n
for i in range(n):
  l,r=map(int,sys.stdin.readline().split())
  lr.append(l)
  rr.append(r)
k=int(input())
for i in range(n):
  if k>=lr[i] and k<=rr[i]:
    suma=n-i
    break
  else:
    suma-=1
print (suma)