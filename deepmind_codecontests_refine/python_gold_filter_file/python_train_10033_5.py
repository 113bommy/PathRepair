def sievearray():
  n=3000
  sieve=[1 for i in range(n+1)]
  sieve[0]=0
  sieve[1]=0
  i=2
  while i*i<=n:
    if sieve[i]==1:
      for j in range(i*i,n+1,i):
        sieve[j]=0
    i+=1
  return sieve
def almost_prime(n,sieve,flag):
  n1=round(n**0.5)
  count=0
  for i in range(2,n1+1):
    if n%i==0:
      if sieve[i]==1:
        count+=1
      if sieve[n//i]==1 and n//i!=i:
        count+=1
  if count==2:
    flag+=1
  return flag
flag=0
n=int(input())
sieve=sievearray()
if n<6 and n>=1:
  print(0)
else:
  for i in range(6,n+1):
    flag=almost_prime(i,sieve,flag)
  print(flag)
  
  
  

      
