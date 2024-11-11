po=0
neg=0
for i in range(int(input())):
     x,y=map(int,input().split())
     if x>0:
          po+=1
     else:
          neg+=1
if min(po,neg)<=1:
     print("Yes")
else:
     print("No")
          
     
