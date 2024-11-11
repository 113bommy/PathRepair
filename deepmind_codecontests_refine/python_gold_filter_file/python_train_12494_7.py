A=[]
B=[]
a=i=0
for c in input():
 if"\\"==c:A+=[i]
 elif"/"==c and A:
  j=A.pop()
  t=i-j
  a+=t
  while B and B[-1][0]>j:t+=B[-1][1];B.pop()
  B+=[(j,t)]
 i+=1
print(a)
if B:print(len(B),*list(zip(*B))[1])
else:print(0)
