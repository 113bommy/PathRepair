for _ in range(int(input())):
  s=[int(n) for n in input().split()]
  l=s[0]
  r=s[1]
  d=s[2]
  
  p=0
  if l>d:
    print(d)
    p=1
  if p==0:
    j=r//d+1
    print(j*d)