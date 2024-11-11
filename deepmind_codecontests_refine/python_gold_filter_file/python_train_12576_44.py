N=int(input())
S=[input() for i in range(N)]
BXA=0;XA=0;BX=0;ans=0;
for s in S:
  ans+=s.count("AB")
  if(s[0]=='B' and s[-1]=='A'):
    BXA+=1
  elif(s[0]=='B'):
    BX+=1
  elif(s[-1]=='A'):
    XA+=1
#print(ans,min([XA,BX]))
if min([XA,BX])>0:
  ans+=min([XA,BX])+BXA
elif max([XA,BX])>0:
  ans+=BXA
else:
  ans+=max([BXA-1,0])
print(ans)
  
    