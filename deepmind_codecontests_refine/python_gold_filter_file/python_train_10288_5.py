import sys
n=int(input())
lst=[]
for i in range(n):
  x,y,h=map(int,input().split())
  lst.append([x,y,h])
  
for j in range(101):
  for k in range(101):
    for i in range(n):
      H=abs(j-lst[i][0])+abs(k-lst[i][1])+lst[i][2]
      if H>0:
        if all(max(H-abs(j-lst[l][0])-abs(k-lst[l][1]),0)==lst[l][2] for l in range(n)):
          print(j,k,H)
          sys.exit()
        
  
  
