s=list(input())
s+="2"
a=[]
c=0
for i in range(len(s)-1):
  c+=1
  if s[i]!=s[i+1]:
    a.append(c)
    c=0
ansl=[]
for i in range(len(a)//2):
  t1=a[2*i]//2;r1=a[2*i]-t1
  t2=a[2*i+1]//2;r2=a[2*i+1]-t2
  flag=["0" for j in range(a[2*i]-1)]+[str(r1+t2)]+[str(r2+t1)]+["0" for j in range(a[2*i+1]-1)]
  ansl+=flag
print(" ".join(ansl))
