import math
T=int(input())
for t in range(T):
  n=int(input())
  #n,m,k=map(int,input().split())
  #lst=list(map(int,input().split()))
  i=2
  j=n-3

  while(1):
    if math.gcd(i,j)==1:
      print(i,j,1)
      break
    else:
      i+=1
      j-=1