s=[]
p=[]
a=i=0
for c in input():
 if"\\"==c:s+=[i]
 elif"/"==c and s:
  j=s.pop()
  t=i-j
  a+=t
  while p and p[-1][0]>j:t+=p[-1][1];p.pop()
  p+=[(j,t)]
 i+=1
print(a)
if p:print(len(p),*list(zip(*p))[1])
else:print(0)
