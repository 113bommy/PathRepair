R={"*":2,"/":2,"+":1,"-":1,"(":0,")":0}
for _ in[0]*int(input()):
 L=[];t=''
 for e in input()[:-1]:
  if e.isdigit():t+=e
  else:
   if t:L+=[t];t=''
   L+=e
 if t:L+=[t]
 P,S=[],[]
 for i in L:
  if"("==i:S+=i
  elif")"==i:
   while"("!=S[-1]:P+=S.pop()
   S.pop()
  elif i in R:
   while S and R[S[-1]]>=R[i]:P+=S.pop()
   S+=i
  else:P+=[i]
 while S:P+=S.pop()
 for x in P:
  S+=[str(int(eval(S.pop(-2)+x+S.pop())))if x in"+-*/"else x]
 print(*S)
