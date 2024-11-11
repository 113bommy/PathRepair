n=int(input())
s=input()
ctr=0;i=0
if len(s)==1:
  print(1)
else:
  while True:
    a=s[i];b=s[i+1]
    if a==b:
      z=1;i+=1;
    else:
      ctr+=1
      i+=2
    if i>=len(s)-1:
      break
  print(len(s)-ctr)