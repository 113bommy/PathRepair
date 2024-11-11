import sys
n=int(input())
s=int(input())
if n==s:
  print(n+1)
  sys.exit()
if n<s:
  print(-1)
  sys.exit()
for i in range(2,int(n**0.5)+1):
  ct=0;x=n;b=i
  while x>=b:
    ct+=x%b
    x=x//b
  ct+=x
  if ct==s:
    print(b)
    sys.exit()
for i in range(int(n**0.5),0,-1):
  if (n-s)%i==0:
    ct=0;x=n;b=(n-s)//i+1
    while x>=b:
      ct+=x%b
      x=x//b
    ct+=x
    if ct==s:
      print(b)
      sys.exit()
print(-1)