a,b=map(int,input().split())
if a==b :
  print (1)
elif ((b-a) <10) :
  if ((a%10) < (b%10)) :
    p=1
    for i in range (a%10+1,b%10+1):
      p=p*i
    print (p%10)
  else :
    print (0)
else :
  print (0)