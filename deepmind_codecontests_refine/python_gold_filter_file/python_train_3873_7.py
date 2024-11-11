
for _ in range(int(input())):
  n = int(input())
  na = list(input())
  nb = list(input())
  k=0
  zz = len(na)    
  ans = []
  for i in range(zz):
    f = 0
    if(na[i]==nb[i]):
      f= 1
    if(not f):  
      for j in range(i+1,zz):
        if(na[j]==na[i]):
          ans.append((j+1,i+1))
          na[j] = nb[i]
          f = 1
          break
    if(not f):
      for j in range(i+1,zz):
        if(na[i]==nb[j]):
          ans.append((j+1,j+1))
          ans.append((j+1,i+1))
          nb[j] = na[j]
          na[j] = nb[i]
          f = 1
          break
    #print(na,nb)    
    if(not f):
      k  =1
      break
  if(k):
    print("NO")
  else:
    print("YES")
    print(len(ans))
    for t in ans:
      print(t[0],t[1])           
          

