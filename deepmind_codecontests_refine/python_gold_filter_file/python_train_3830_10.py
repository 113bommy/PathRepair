def main():
  from bisect import bisect
  n,k,*a=map(int,open(0).read().split())
  a.sort()
  i=bisect(a,0)
  a,b=a[i:],a[i-1::-1]
  n,m=len(a),len(b)
  ok=10**18
  ng=-ok
  while ok-ng>1:
    x=(ok+ng)//2
    s=0
    if x>=0:
      s+=n*m
      t=0
      i=n
      for y in a:
        while i and a[i-1]*y>x:i-=1   
        t+=i
        if y*y<=x:t-=1
      s+=t//2
      t=0
      i=m
      for y in b:
        while i and b[i-1]*y>x:i-=1
        t+=i
        if y*y<=x:t-=1
      s+=t//2
    else:
      i=m
      for y in a:
        while i and b[i-1]*y<=x:i-=1
        s+=m-i
    if s>=k:ok=x
    else:ng=x
  print(ok)
main()