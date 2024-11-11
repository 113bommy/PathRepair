t=int(input())
for k in range(t):
  n=int(input())
  a=list(map(int,input().split()))
  import math
  e=min(a)
  s=set(a)
  b=sorted(a)
  
  # print(a,b)
  def yesno(a,b):
    flag=1
    c=[0]*(len(b))
    for i in range(len(a)):
        if(a[i]==b[i]):
            c[i]=1
    for i in range(len(a)):
        if(c[i]==1):
            continue
        if(a[i]%e!=0):
            flag=0
    if(flag==1):
        return("YES")
    else:        
        return("NO")
  print(yesno(a,b))