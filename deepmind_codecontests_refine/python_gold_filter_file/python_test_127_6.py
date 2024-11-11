kl = int(input())
for kkl in range(kl):
 
  str=input()
  t=input()
  sp=list(str)
  sp.sort()
  sp.append(1)
  i=0

  if "a" in sp and "b" in sp and "c" in sp and t=="abc":
    while sp[i]=="a":
      i+=1
    ka=i
    while sp[i]=="b":
      i+=1
    kb=i
    while sp[i]=="c" and i<len(sp):
      i+=1
    if i == len(sp):
      i+=1
    t=min(kb-ka, i-kb)
    sp[ka:ka+t], sp[i-t:i]=["c"]*t, ["b"]*t

  for i in range(len(sp)-1):
    print(sp[i], end="")
  print()
    