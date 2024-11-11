import sys
n,k=map(int,input().split())
w=list(map(int,sys.stdin.readlines()))
def f():
 i=0
 for _ in[0]*k:
  s=0
  while s+w[i]<=m:
   s+=w[i];i+=1
   if i==n:return n
 return i
l,r=max(w),sum(w)
while l<r:
 m=(l+r)//2
 if f()>=n:r=m
 else:l=m+1
print(r)
