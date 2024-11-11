while 1:
  R0,W0,C,R=map(int,input().split())
  if not R0 and not W0 and not C and not R:break
  n=0
  while 1:
    if W0>1 and int((R0+R*n)/W0)>=C:break
    elif W0==1 and (R0+R*n)>=C:break 
    n+=1
  print(n)


