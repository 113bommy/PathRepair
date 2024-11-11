s=input()
d={}
for i in s:
    if i not in d:
        d[i]=1
    else:
        d[i]+=1
e=0
o=0       
for j in d.values():
    if j%2==0:
        e+=1
    else:
        o+=1
win=-1
while (o>1):
    if e>0:
        e-=1
        o+=1
    elif e==0:
        o-=1
    win=-win
if win==-1:
 print("First")
else:
 print("Second")
