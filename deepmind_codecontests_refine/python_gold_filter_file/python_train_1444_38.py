n=int(input())
s=int(input())
if n==s:
  print(n+1)
  exit()
if n<s:
  print(-1)
  exit()
for b in range(2,int(n**(1/2))+1):
  m=n
  wa=0
  while m>0:
    wa+=m%b
    m=m//b
  if wa==s:
    print(b)
    exit()

for p in range(int((n-1)**(1/2)),0,-1):
  if (n-s)%p==0:
    b=(n-s)//p+1
    if p+n%b==s:
      print(b)
      exit()
print(-1)
