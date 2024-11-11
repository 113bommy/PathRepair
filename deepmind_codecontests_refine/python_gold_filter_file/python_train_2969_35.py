x=input()
x=x.split(" ")
if (x[2]=="week"):
    if int(x[0])==5 or int(x[0])==6:
      print(53)
    else:
      print(52)
else:
  if int(x[0])<30 :
    print(12)
  elif int(x[0])==30 :
    print(11)
  elif int(x[0])==31 :
    print(7)
