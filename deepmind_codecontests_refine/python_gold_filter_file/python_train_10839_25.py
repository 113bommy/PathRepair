c=int(input())
i=0
while i<c :
  ab=input().split()
  a=int(ab[0])
  b=int(ab[1])
  k=int(ab[2])
  if k % 2 !=0 : 
    print(a*(int(k/2)+1)-b*(int(k/2)))
  else :  
    print(a*(int(k/2))-b*(int(k/2)))
  i=i+1