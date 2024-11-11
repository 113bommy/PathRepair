n=int(input())
a=list(map(int,input().split()))
l=[0]*(10**6+100)
x=0
for m in a:
  l[m]+=1

j=2
#print(l)


while j <10**6+1:
  c=0
  k=1
  while j*k<=10**6+1 :
    if l[j*k]>0:
      c+=l[j*k]
    k+=1

  if c==n:
    print("not coprime")
    exit()
  elif c>1:
    x=1
  j+=1 
  
if x==1:
  print("setwise coprime")
else:
  print("pairwise coprime")
  
    
