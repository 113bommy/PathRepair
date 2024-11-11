def gcd(a, b):
  if a==0:
    return b
  elif b==0:
    return a
  else:
    if a>b:
      return gcd (a%b, b)
    else:
      return gcd (a, b%a)

n, m, k = map(int, input().split())
n1, m1, k1=n, m, k
f=0
if (2*m*n)%k!=0:
  print ("NO")
else:
  f=0
  if k%2==0:
    k=k//2
    f=1
  t=gcd(n, k)
  while t!=1:
    n=n//t
    k=k//t
    t=gcd(n, k)
  t=gcd(m, k)
  while t!=1:
    m=m//t
    k=k//t
    t=gcd(m, k)
  if f==0:
    if m*2<=m1:
      m*=2
      print ("YES")
      print ('0 0')
      print (0, m)
      print (n, 0)
    else:
      if n*2<=n1:
        n*=2
        print ("YES")
        print ('0 0')
        print (0, m)
        print (n, 0)
      else:
        print ('NO')
  else:
    if n<=n1 and m<=m1:
      print ("YES")
      print ('0 0')
      print (0, m)
      print (n, 0)
    else:
      print ("NO")