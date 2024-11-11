a=[];b=[]
for x in sorted(map(int,[*open(0)][1].split())):
  if len(a)<1 or a[-1]!=x:a+=[x]
  elif len(b)<1 or b[0]!=x:b=[x]+b
if len(b)>0 and a[-1]==b[0]:b=b[1:]
print(len(a)+len(b))
print(*a,*b)