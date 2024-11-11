a=input()
up=0
lo=0
di=0
sp=0
for i in range(len(a)):
  if a[i].isupper():
    up+=1
  elif a[i].islower():
    lo+=1
  elif a[i].isdigit():
    di+=1
  else:
    sp+=1
if up>0 and lo>0 and di>0 and len(a)>4:
  print("Correct")
else:
  print("Too weak")

  
    
    