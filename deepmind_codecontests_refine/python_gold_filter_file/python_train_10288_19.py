n=int(input())
XYH=[]
for i in range(n):
  x,y,h=map(int,input().split())
  XYH.append([x,y,h])
XYH.sort(key=lambda x:x[2])
for i in range(101):
  for j in range(101):
    peak=abs(i-XYH[-1][0])+abs(j-XYH[-1][1])+XYH[-1][2]
    flag=1
    for k in range(n-1):
      if max(0,peak-abs(i-XYH[k][0])-abs(j-XYH[k][1]))!=XYH[k][2]:
        flag=0
    if flag==1:
      Ans=[i,j,peak]
print(*Ans)