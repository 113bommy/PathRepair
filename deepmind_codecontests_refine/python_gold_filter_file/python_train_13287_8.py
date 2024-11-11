N,a,b=map(int,(input().split(" ")))
if(N==(a+b)):
  print("1")
elif(a>=(b*N) or (b>=N*a)):
  if(a>b):
    print(b)
  else:
    print(a)
elif(a==b and N==2):
  EE=int((a+b)//N)
  print(EE)
else:
  if(a>b):
    a1=a
    b1=b
    i=1
  else:
    b1=a
    a1=b
    i=1
  while(i<a1+1):
    w=int(b1//i)
    w1=int(a1//i)
    if(w+w1>=N):
      i=i+1
    else:
      result=i-1
      break
  print(result)