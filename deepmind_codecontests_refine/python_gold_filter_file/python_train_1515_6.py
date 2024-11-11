li=list(map(int,input().split()))
ki=[]
for i in range(len(li)):
 k=li.count(li[i])
 if k>1:
   if k==2:
    ki.append(sum(li)-li[i]*2)
   else:
    ki.append(sum(li) - li[i] * 3)
if len(ki)>0:
 print(min(ki))
else:
  print(sum(li))