n,l=map(int,input().split())
s=(l-1)*(n-1)+n*(n+1)//2
if l>=1:
  print(s-1)
elif n>=1-l:
  print(s-1+l)
else:
  print(s-n)