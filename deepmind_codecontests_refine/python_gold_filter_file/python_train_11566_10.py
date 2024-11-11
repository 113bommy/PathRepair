n=int(input())
l=list(map(int,input().split()))
n1=l.count(1)
n2=[]
if(n>1):
  for i in range(1,n):
     if(l[i]==1):
        n2.append(l[i-1])
  n2.append(l[i])
  print(n1)
  print(*n2)
else:
    print(n1)
    print(1)
