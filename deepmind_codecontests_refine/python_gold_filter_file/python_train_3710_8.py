h1, a1, c1= map(int,input().split())
h2, a2 =map(int,input().split())
if h2<a1:
   print(1)
   print ("STRIKE") 
else:
  j=h2%a1
  if j==0:
     kolud=int(h2//a1-1)
  else:
      kolud=int(h2//a1)  
  uron=c1-a2 
  zdorowje=h1-kolud*a2
  lechenie=0
  while zdorowje<=0:
      zdorowje+=uron
      lechenie+=1
  print(lechenie+kolud+1)
  for i in range(lechenie):
      print("HEAL")
  for  i in range(kolud+1):
      print ("STRIKE")  
     
