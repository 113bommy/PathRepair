N=int(input())
a=list(map(int,input().split()))
a.sort()
a.reverse()

h=[]
count=0
f=0
for i in a:
 if f==i:
  h.append(i)
  count+=1
  f=0
 else:
   f=i
   if count==2:
       break 
if count==2:
 print(h[0]*h[1])
else:
 print(0)