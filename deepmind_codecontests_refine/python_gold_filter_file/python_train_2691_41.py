n,a,b=map(int,input().split())
h=[int(input())for _ in range(n)]
ok=10**9
ng=0
while ng+1!=ok:
  mid=(ok+ng)//2
  s=0
  for i in h:
    j=max(i-mid*b,0)
    s+=0--j//(a-b)
  if s>mid:ng=mid
  else:ok=mid
print(ok)